#include "Customer.h"
/*
 * @file Customer.h
 * @author Katarina McGaughy
 * Customer is a type of Object that represents a customer for the store
 * The Customer has a name, ID number, and a transactionHistory log of all
 * transactions made
 *
 * Features:
 * - create a transaction (Buy or Sell)
 * - display all customers transactions
 *
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */


 /**
  * @brief Construct a new Customer object
  * creates a new customer with name and customerID
  *
  * @param n : name of customer
  * @param ID : customer ID
  */
Customer::Customer(string n)  {

    //fill in customer data 
    vector<string> v;
    stringstream ss(n);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }

    
    customerID = v[0];
    name = v[1];
    name.erase(name.begin());

}

/**
 * @brief Construct a new Customer object
 * creates a new customer with Customer c
 *
 * @param c : instance of customer
 */
Customer::Customer(const Customer& c) {
    name = c.name;
    customerID = c.customerID;
    clearTransactions();
    for (int i = 0; i < c.transactionHistory.size(); i++) {
        transactionHistory.push_back(c.transactionHistory[i]);
    }
}

/**
 * @brief Destroy the Customer object
 * deallocate vector of transactions and delete them
 */
Customer::~Customer()
{
    clearTransactions();
}

/**
* getName
* Preconditions: none
* Postconditions: returns customer name
*/
string Customer::getName() const {
    return name;
}

/**
* getCustomerID
* Preconditions: none 
* Postconditions: returns customer ID
*/
string Customer::getCustomerID() const {
    return customerID;
}

/**
 * displayCustomerTransactions
 * prints the vector of transactions that are updated by
 * file of transactions
 */
void Customer::displayCustomerTransactions() const
{
    cout << customerID << " " << name << " transactions:";
    if (transactionHistory.empty()) {
        cout << " none " << endl;
    }
    else {
        cout << endl;
        for (int i = 0; i < transactionHistory.size(); i++)
        {
            transactionHistory[i]->printTransaction();
        }
    }
}

/**
 * operator< overload
 * sorts customers in alphabetical order for the priority queue
 *
 * Preconditons: another customer object must be initialized
 * Postconditons: true will be returned if current Customer
 * is earlier in the alphabet than cust
 * @param cust : customer to be compared to
 * @return true : if cust is larger
 * @return false : if cust is smaller
 */
bool Customer::operator<(const Comparable& cust) const {
    const Customer& c = static_cast<const Customer&>(cust);
    if (this->name < c.name) {
        return true;
    }
    return false;
}

/**
* operator>
* this function returns true if the current object is greater than the
* rhs object
* Precondition: there is another Comparable object that is initialized
* Postcondition: true if the current object is greater than rhs object
* @param rhs: Comparable to be compared to current object
* @return: true if the current Comparable objects is greater
*/
bool Customer::operator>(const Comparable& rhs) const {
    return !operator<(rhs);
}

/**
* operator==
* this function compares two Comparables for equality
* Precondition: there is another Comparable object that is initialized
* Postcondition: true if the two objects are equal
* @param rhs: Comparable to be compared to current object
* @return: true if Comparable objects are equal
*
*/
bool Customer::operator==(const Comparable& colToCompare) const {
    const Customer& c = static_cast<const Customer&>(colToCompare);
    if ((this->name == c.name) && (this->customerID == c.customerID)) {
        return true;
    }
    return false;
}

/**
* operator!=
* this function compares two Comparables for inequality
* Precondition: there is another Comparable object that is initialized
* Postcondition: true if the two objects are not equal
* @param rhs: Comparable to be compared to current object
* @return: true if Comparable objects are not the same
*/
bool Customer::operator!=(const Comparable& rhs) const {
    return !operator==(rhs);
}

/**
* copy
* this function returns a copy of the Comparable c
*/
Comparable* Customer::copy(const Comparable& c) {
    const Customer& cust = static_cast<const Customer&>(c);
    return new Customer(cust);
}

/**
* clearTransactions
* this function clears all transcations
* Precondtions: none
* Postcondiitons: Transactions is empty 
*/
void Customer::clearTransactions() {
    for (int i = 0; i < transactionHistory.size(); i++) {
        if (transactionHistory[i] != nullptr) {
            delete transactionHistory[i];
            transactionHistory[i] = nullptr;
        }
    }
    transactionHistory.clear();
}

/**
 * purchaseItem
 * this function takes in a collectible item and decrements
 * inventory of item by one and creates a transaction that
 * is added to the transactionHistory vector
 *
 * @param item : Collectible item to be purchased
 * @return true : if the purchase was complete
 * @return false : if the purchase was not complete
 */
void Customer::purchaseItem(Collectible* item)
{
    Transaction* t = new Transaction(item, 'B');
    transactionHistory.push_back(t);
}

/**
 * sellItem
 * this function takes in a collectible item and increments
 * inventory of item by one and creates a transaction that
 * is added to the transactionHistory vector
 *
 * @param item : Collectible item to be sold
 * @return true : if the purchase was complete
 * @return false : if the purchase was not complete
 */
void Customer::sellItem(Collectible* item) {
    if (custHasCollectible(item)) {
        Transaction* t = new Transaction(item, 'S');
        transactionHistory.push_back(t);
        //increment the inventory count
    }
    else {
        Transaction* t = new Transaction(item, 'F');
        transactionHistory.push_back(t);
    }
}

/**
* custHasCollectible
* this function takes in a collectible pointer to item
* and returns true if the customer has it 
* Precondtions: item must be initialized
* Postcondiitons: returns true if customer has the item
*/
bool Customer::custHasCollectible(Collectible* item) {
    for (int i = 0; i < transactionHistory.size(); i++) {
        if (*transactionHistory[i]->getItem() == *item) {
            return true;
        }
    }
    return false;
}

/**
* print
* this function prints Comparable
*/
void Customer::print() const {
    displayCustomerTransactions();
}