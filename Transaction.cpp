#include "Transaction.h"
/*
 * @file Transactions.h
 * @author Katarina McGaughy
 * Transactions class stores a pointer to a Collectible item
 * and flags is the item is sold or bought in the transaction
 *
 * Features:
 * -store transaction
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */


 /**
  * @brief Construct a new Transaction object
  *
  * @param it : Collectible pointer
  * @param transactionType : if char is B then its a buy,
  * and purchased is true
  * if char is S then sold is true
  */
Transaction::Transaction(Collectible* it, char transactionType) :
    item(it), transType(transactionType) {}

/**
 * @brief Destroy the Transaction object
 *
 */
Transaction::~Transaction()
{
    item = nullptr;
}

/**
* getItem
* Preconditions: none
* Postconditions: returns the item sold or
* bought
*/
Collectible* Transaction::getItem() const {
    return item;
}

/**
* printTransaction
* Preconditions: none
* Postconditions: prints the transaction
*/
void Transaction::printTransaction() const {
    if (transType == 'S') {
        cout << "Sold to store: ";
    }
    else if (transType == 'F') {
        cout << "Transaction failed for: ";
    }
    else {
        cout << "Bought from store: ";
    }
    item->print();

} 

