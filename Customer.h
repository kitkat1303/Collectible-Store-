#pragma once
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
#include "Object.h"
#include "Transaction.h"
#include "Collectible.h"
//#include "Inventory.h"
#include <vector>
#include "Comparable.h"

class Customer : public Comparable
{

private:
    string name = "";
    string customerID = "";
    vector<Transaction*> transactionHistory; // transactions ordered in chronological order

public:
    /**
     * @brief Construct a new Customer object
     *
     */
    Customer() {}

    /**
     * @brief Construct a new Customer object
     * creates a new customer with name and customerID
     *
     * @param n : name of customer
     * @param ID : customer ID
     */
    Customer(string n);

    /**
     * @brief Construct a new Customer object
     * creates a new customer with Customer c
     *
     * @param c : instance of customer
     */
    Customer(const Customer& c);

    /**
    * getName
    * Preconditions: none
    * Postconditions: returns customer name
    */
    string getName() const;

    /**
    * getCustomerID
    * Preconditions: none
    * Postconditions: returns customer ID
    */
    string getCustomerID() const;

    /**
     * @brief Destroy the Customer object
     * deallocate vector of transactions and delete them
     */
    ~Customer();

    /**
     * displayCustomerTransactions
     * prints the vector of transactions that are updated by
     * file of transactions
     */
    void displayCustomerTransactions() const;

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
    bool operator<(const Comparable& colToCompare) const override;

    /**
    * operator>
    * this function returns true if the current object is greater than the
    * rhs object
    * Precondition: there is another Comparable object that is initialized
    * Postcondition: true if the current object is greater than rhs object
    * @param rhs: Comparable to be compared to current object
    * @return: true if the current Comparable objects is greater
    */
    bool operator>(const Comparable& rhs) const override;

    /**
    * operator==
    * this function compares two Comparables for equality
    * Precondition: there is another Comparable object that is initialized
    * Postcondition: true if the two objects are equal
    * @param rhs: Comparable to be compared to current object
    * @return: true if Comparable objects are equal
    *
    */
    bool operator==(const Comparable& colToCompare) const override;

    /**
    * operator!=
    * this function compares two Comparables for inequality
    * Precondition: there is another Comparable object that is initialized
    * Postcondition: true if the two objects are not equal
    * @param rhs: Comparable to be compared to current object
    * @return: true if Comparable objects are not the same
    */
    bool operator!=(const Comparable& rhs) const override;

    /**
    * copy
    * this function returns a copy of the Comparable c
    */
    Comparable* copy(const Comparable& c) override;

    /**
    * clearTransactions
    * this function clears all transcations
    * Precondtions: none
    * Postcondiitons: Transactions is empty
    */
    void clearTransactions();

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
    void purchaseItem(Collectible* item);

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
    void sellItem(Collectible* item);

     /**
    * custHasCollectible
    * this function takes in a collectible pointer to item
    * and returns true if the customer has it
    * Precondtions: item must be initialized
    * Postcondiitons: returns true if customer has the item
    */
    bool custHasCollectible(Collectible* item);

    /**
    * print
    * this function prints Comparable
    */
    void print() const override;
};


