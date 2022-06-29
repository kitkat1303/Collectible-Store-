#include "CollectibleStore.h"
/*
 * @file CollectibleStore.h
 * @author Katarina McGaughy
 * CollectibleStore is a type of Store that contains a list of
 * Inventory, Customers, and Commands that the store can do like:
 * Buy, Sell, Display, DisplayCustomers, and DisplayHistory
 *
 * Features:
 * -read in information from file
 * -store customer, commands, and inventory from files
 * -subclass of Store
 *
 * Assumptions:
 * -file is in correct format
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <vector>
#include "CustomerList.h"
#include "Inventory.h"

 /**
  * Constructor
  * construct a new Collectible Store object
  * sets the commands vectors to nullptr
  * initializes the cList and iList **do these need to be pointers??
  *
  */
CollectibleStore::CollectibleStore() {
	cList = new CustomerList(); 
	iList = new Inventory();
}

/**
 * Destructor
 * deallocate all vector of commands
 * destructors for CustomerList and Inventory should handle their memory
 */
CollectibleStore::~CollectibleStore() {

	//set customerList and inventoryList to nullptr
	cList = nullptr;
	iList = nullptr;
}

/**
 * @brief initializeInventory
 * reads in a file line by line and initializes collectible items
 * and creates a hash table of items as well as a sorted list of
 * items in the Inventory class
 * Preconditions: file must exist
 * Postconditions: Inventory is built
 */
void CollectibleStore::initializeInventory(ifstream& infile) {
	cout << "Initializing inventory: " << endl;
	vector<Object*> collectibles;
	vector<string> keys;
	string line;
	while (getline(infile, line)) {
		Collectible* col;
		col = i.createCollectible(line);
		if (col != nullptr) {
			collectibles.push_back(col);
			keys.push_back(col->getKey());
		}
	}
	iList->buildInventory(collectibles, keys);
	iList->displayInventory();

	for (int i = 0; i < collectibles.size(); i++) {
		collectibles[i] = nullptr;
	}
	
}

/**
 * @brief initializeCustomers
 * reads in a file line by line and initializes customers
 * and creates a hash table of customers with their ID as the key
 *  as well as creates a sorted list of customers (alphabetical)
 * in the CustomerList class
 * Preconditions: file must exist
 * Postconditions: CustomerList is built
 */
void CollectibleStore::initializeCustomers(ifstream& infile) {

	cout << "Initializing customers: " << endl;
	vector<string> keys;
	vector<Object*> customers;
	string line;
	while (getline(infile, line)) {
		customers.push_back(new Customer(line));
	}
	for (int i = 0; i < customers.size(); i++) {
		
		const Customer* s = dynamic_cast<const Customer*>(customers[i]);
		keys.push_back(s->getCustomerID());
	}

	//build customerLists
	cList->buildCustomerList(customers, keys);
	cList->displayCustomers();

	for (int i = 0; i < customers.size(); i++) {
		customers[i] = nullptr;
	}
}

/**
 * getCommands
 * this function reads in commands from a file and
 * initializes them via the CommandFactory and
 * stores them in the commands vector
 * Preconditions: file must be in the correct format
 * Postconditions: commands vector is filled
 *
 * @param file : file of commands
 */
void CollectibleStore::getCommands(ifstream& infile) {


	vector<Command*> listCommands;
	string line;
	while (getline(infile, line)) {
		Command* newCommand;
		newCommand = c.createCommand(line);
		//need to ensure commands are valid 
		if (newCommand != nullptr) {
			listCommands.push_back(newCommand);
		}
	}
	executeCommands(listCommands);
}


/**
 * @brief executeCommands
 * this function takes in a vector of commands 
 * Preconditions: vector of commands must be initialized
 * Postconditions: commands are executed
 */
void CollectibleStore::executeCommands(vector<Command*> commandList) {

	for (int i = 0; i < commandList.size(); i++) {
		commandList[i]->Execute(cList, iList);
		//delete commands
		delete commandList[i];
		commandList[i] = nullptr;
	}
	commandList.clear();
}



/**
* createCommand
* Create a Command object
*
* @param desc : string that is read in from file
* @return Command* : new Command object
*/
CollectibleStore::Command* CollectibleStore::CommandFactory::createCommand(string desc)
{

	char firstChar = desc[0];
	if (firstChar == 'B') {
		
		return new Buy(desc);
	}
	else if (firstChar == 'S') {
		return new Sell(desc);
	}
	else if (firstChar == 'D') {
		return new Display(desc);
	}
	else if (firstChar == 'C') {
		return new CustomerDisplay(desc);
	}
	else if (firstChar == 'H') {
		return new History(desc);
	}
	cout << "Command: " << desc;
	cout << " is not recognized.Try again." << endl;
	cout << endl;
	return nullptr;
}


/**Execute
* this functions takes in a CustomerList and InventoryList
* and sells a Collectible item to a customer 
* Preconditions: CustomerList and InventoryList must be initialized
* Postconditions: if the customer and collectible exist and the 
* inventory count of the collectible is not 0, a purchase is made
* by the customer and stored in transactions for the customer
* if the customer or collectible do not exist, an error message is displayed
*/
void CollectibleStore::Sell::Execute(CustomerList* cList, Inventory* iList) {

	//B, 456, M, 1913, 70, Liberty Nickel

	string str(command);

	vector<string> v;
	stringstream ss(str);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		v.push_back(substr);
	}

	string customerID = v[1];

	string colDesc = command;
	//colDesc is now just the type, year, grade, and name
	colDesc.erase(0, 8);
	//cout << "Printing description when reading in a buy command:(2) ";
	//cout << colDesc << endl;

	Object* col = iList->getCollectible(colDesc);
	Object* cust = cList->getCustomer(customerID);

	if (col != nullptr && cust != nullptr) {
		Customer* cu = dynamic_cast<Customer*>(cust);
		Collectible* co = dynamic_cast<Collectible*>(col);
		int count = co->getCount();
		if (count > 0) {
			cu->purchaseItem(co);
			//decrement by one in inventory 
			count--;
			co->setCount(count);
		}
		else {
			cout << "Inventory for collectible item: " << co->getKey();
			cout << " is 0, purchase can not be made." << endl;
			cout << endl;
		}
		//set pointer to nullptr
		cu = nullptr;
		co = nullptr;
	}
	else {
		cout << "Customer: " << customerID << " or Collectible: " << colDesc;
			cout << " does not exist.Try again." << endl;
			cout << endl;
	}

}

/**Execute
* this functions takes in a CustomerList and InventoryList
* and buys a Collectible item from a customer
* Preconditions: CustomerList and InventoryList must be initialized
* Postconditions: if the customer and collectible exist and the
* customer has the collectible, the item is bought and added to 
* inventory of the store and the transactions for customer is updated.
* If the customer or collectible do not exist, an error message is displayed
*/
void CollectibleStore::Buy::Execute(CustomerList* cList, Inventory* iList) {

	//B, 456, M, 1913, 70, Liberty Nickel

	//parse string to get item and customer ID 
	string str(command);
	vector<string> v;
	stringstream ss(str);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		v.push_back(substr);
	}

	//set customerID
	string customerID = v[1];

	string colDesc = command;
	//colDesc is now just the type, year, grade, and name
	colDesc.erase(0, 8);
	//cout << "Printing description when reading in a buy command:(2) ";
	//cout << colDesc << endl;

	//find collectible item and customer 
	Object* col = iList->getCollectible(colDesc);
	Object* cust = cList->getCustomer(customerID);
	if (col != nullptr && cust != nullptr) {
		Customer* cu = dynamic_cast<Customer*>(cust);
		Collectible* co = dynamic_cast<Collectible*>(col);
		int count = co->getCount();
		//ensure customer has item
		if (cu->custHasCollectible(co)) {
			cu->sellItem(co);
			//decrement by one in inventory 
			count++;
			co->setCount(count);
		}
		else {
			cout << "Customer: " << customerID << " does not have item: " << co->getKey();
			cout << " . Can not buyitem from customer." << endl;
			cout << endl;
		}
		//set pointer to nullptr
		cu = nullptr;
		co = nullptr;
	}
	else {
		cout << "Customer: " << customerID << " or Collectible: " << colDesc;
		cout << " does not exist.Try again." << endl;
		cout << endl;
	}


}


/**Execute
* this functions takes in a CustomerList and InventoryList
* and sells a Collectible item to a customer
* Preconditions: CustomerList and InventoryList must be initialized
* Postconditions: the entire stored inventory is displayed
*/
void CollectibleStore::Display::Execute(CustomerList* cList, Inventory* iList) {
	cout << "(D) Displaying Inventory: " << endl;
	iList->displayInventory();
	cout << endl;
}


/**Execute
* this functions takes in a CustomerList and InventoryList
* and sells a Collectible item to a customer
* Preconditions: CustomerList and InventoryList must be initialized
* Postconditions: if the customer exists, the transactions for the customer
* are displayed, if the customer does not exist, an error message is displayed
*/
void CollectibleStore::CustomerDisplay::Execute(CustomerList* cList, Inventory* iList) {

	cout << "(C) Displaying single customer: " << endl;

	//parse command to find customer
	string str(command);
	vector<string> v;
	stringstream ss(str);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		v.push_back(substr);
	}

	string customerID = v[1];

	//display customer based on customer ID
	cList->displaySingleCustomer(customerID);
	cout << endl;

}

/**Execute
* this functions takes in a CustomerList and InventoryList
* and sells a Collectible item to a customer
* Preconditions: CustomerList and InventoryList must be initialized
* Postconditions: the entire customer list is printed in alphabetical order and 
* their transactions are displayed
*/
void CollectibleStore::History::Execute(CustomerList* cList, Inventory* iList) {
	cout << "(H) Displaying entire store history: " << endl;
	cList->displayCustomers();
	cout << endl;
}








