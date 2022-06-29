#include "CustomerList.h"

/*
 * @file CustomerList.h
 * @author Katarina McGaughy
 * CustomerList class creates and holds a HashTable of customers
 * along with a sorted vector of Customers. It also has functions
 * that display the customers in the correct order and another function
 * that will use the HashTable to print out the transactions of a single
 * customer
 *
 * Features:
 * -display all Customers
 * -display a single Customer
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

 /**
  * buildSortedList
  * this function takes in a vector of Customer pointers
  * and creates a sorted vector that is stored in orderedCustomerList
  *
  * @param customers : vector of Customer pointers
  */
void CustomerList::buildSortedList(vector<Object*>& customers)
{

    for (int i = 0; i < customers.size(); i++) {
        Comparable* cust = dynamic_cast<Comparable*>(customers[i]);
        orderedCustomerList->insert(cust);
    }

}


/**
 * @brief Construct a new Customer List object
 *
 */
CustomerList::CustomerList() {
    orderedCustomerList = new SearchTree();
}

/**
 * @brief Destroy the Customer List object
 *
 */
CustomerList::~CustomerList() {
    orderedCustomerList = nullptr;

}

/**
 * buildCustomerList
 * this function takes in a vector of Customer pointers
 * along with a vector of keys that are associated with th customers
 * and calls buildSortedList in order to have an ordered list of
 * customers and then also creates a HashTable for quick access
 * Preconditons: vectors must be initialized
 * Postconditons: HashTable of customers is built along with
 * an ordered list of Customers
 * @param customer : vector of Customer pointers
 * @param keys : vector of int keys
 */
void CustomerList::buildCustomerList(vector<Object*> customer, vector<string> keys)
{

    buildSortedList(customer);
    customerList.build(customer, keys); // create Hashtable of customers
}

/**
 * displaCustomer
 * this functions displays all customers in
 * alphabetical order along with their entire
 * transaction history
 * PreConditions: none
 * Postcondtions: displays all customers in
 * alphabetical order along with their entire
 * transaction history
 *
 */
void CustomerList::displayCustomers() const {
    orderedCustomerList->print();
}

/**
 * displaySingleCustomer
 * this functions take in the customerID as key to
 * get quick access to an individual customer
 * and prints the customers transactions
 *
 * @param customerID
 */
void CustomerList::displaySingleCustomer(string customerID) const {
    //need to cast
    Object* printCust = customerList.getValue(customerID);
    if (printCust != nullptr) {
        const Customer* s = dynamic_cast<const Customer*>(printCust);
        s->displayCustomerTransactions();
    } 
    else {
        cout << "Customer: " << customerID << " could not be found." << endl;
    }

}

/**
 * getCustomer
 * this functions take in the customerID as key to
 * get quick access to an individual customer
 * and returns a pointer to the customer
 *
 * @param customerID
 */
Object* CustomerList::getCustomer(string customerID) const {
    Object* cust = customerList.getValue(customerID);
    return cust;
}

