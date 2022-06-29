#pragma once
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

#include "Collectible.h"

class Transaction
{
private:
    Collectible* item = nullptr; // item sold or purchased
    char transType = 'N';

public:
    
    /**
     * @brief Construct a new Transaction object
     *
     * @param it : Collectible pointer
     * @param transactionType : if char is B then its a buy,
     * and purchased is true
     * if char is S then sold is true
     */
    Transaction(Collectible* it, char transactionType);

    /**
     * @brief Destroy the Transaction object
     *
     */
    ~Transaction();

    /**
    * printTransaction
    * Preconditions: none 
    * Postconditions: prints the transaction
    */
    void printTransaction() const; 

    /**
   * getItem
   * Preconditions: none
   * Postconditions: returns the item sold or 
   * bought
   */
    Collectible* getItem() const;


};


