#pragma once

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
#include <vector>
#include "HashTable.h"
#include "Customer.h"
#include "SearchTree.h"
#include <queue>

class CustomerList
{
private:
    int numCustomers = 0;
    SearchTree* orderedCustomerList = nullptr; // list of customers in alphabetical order (H)
    // the above vector will get sorted order using a priorityqueue

    //not sure if this needs to be pointer yet...
    HashTable customerList; // hashtable that takes in customer ID and stores pointer to customer which can be used for quick access to customers for updating transactions along with accessing a single customers transaction history (C), allows for quick access to customer info via customer ID for Buy and Sell

    /**
     * buildSortedList
     * this function takes in a vector of Customer pointers
     * and creates a sorted vector that is stored in orderedCustomerList
     *
     * @param customers : vector of Customer pointers
     */
    void buildSortedList(vector<Object*>& customers);

public:
    /**
     * @brief Construct a new Customer List object
     *
     */
    CustomerList();

    /**
     * @brief Destroy the Customer List object
     *
     */
    ~CustomerList(); // deallocates memory

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
    void buildCustomerList(vector<Object*> customer, vector<string> keys);

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
    void displayCustomers() const;

    /**
     * displaySingleCustomer
     * this functions take in the customerID as key to
     * get quick access to an individual customer
     * and prints the customers transactions
     *
     * @param customerID
     */
    void displaySingleCustomer(string customerID) const;

    /*
    getCustomer
    this function takes in a string and finds the customer
    stored in the hash table based on the customerID as key
    Preconditions: none
    Postconditions: Customer pointer is returned for customer
    that matches key
    */
    Object* getCustomer(string customerID) const;
};


