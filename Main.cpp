
/*
 * @file Main.cpp
 * @author Katarina McGaughy
 * Main takes in three files: Customer list, Inventory list, and commands. 
 * It then initializes a CollectibleStore and initializes the customers,
 * inventory, and then executes commands.
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */


#include "Coin.h"
#include "SportsCard.h"
#include "ComicBook.h"
#include "Customer.h"
#include "SearchTree.h"
#include "CustomerList.h"
#include "Inventory.h"
#include "CollectibleStore.h"


int main() {

	CollectibleStore* store = new CollectibleStore();
	ifstream inventoryFile("hw4inventory.txt");
	store->initializeInventory(inventoryFile);
	cout << endl;
	ifstream customerFile("hw4customers.txt");
	store->initializeCustomers(customerFile);
	cout << endl;
	cout << "Executing commands: " << endl;
	ifstream commandFile("hw4commands.txt");
	store->getCommands(commandFile);
	delete store;





	

	return 0;
}
