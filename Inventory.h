#pragma once
/*
 * @file Inventory.h
 * @author Katarina McGaughy
 * Inventory class creates and holds a HashTable of Collectibles
 * along with a sorted vector of Collectibles. It also has functions
 * that display the Collectibles in the correct order
 *
 * Features:
 * -display Collectibles
 * -build Collectible lists
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Object.h"
#include "HashTable.h"
#include "Collectible.h"
#include "SearchTree.h"

class Inventory : public Object
{

private:

    HashTable inventoryList;  // to have access for customer transactions
    SearchTree* orderedCoins = nullptr;
    SearchTree* orderedSportsCards = nullptr;
    SearchTree* orderedComicBooks = nullptr;
    vector<SearchTree*> orderedInventoryList;

    /**
     * buildSortedList
     * this function takes in an array of Collectible pointers
     * and builds a sorted vector of them
     * Preconditons: inventory array must be initialized
     * Postconditions: orderedInventoryList is updated
     * @param inventory : vector of Collectible arrays
     */
    void buildSortedList(vector<Object*>& inventory);

public:

    /**
     * @brief Construct a new Inventory object
     *
     */
    Inventory();

    /**
     * @brief Destroy the Inventory object
     *
     */
    ~Inventory();

    /**
     * buildInventory
     * this function takes in a vector of Collectible pointers and a
     * vector of key strings and calls the buildSortedList function
     * as well as builds HashTable of Collectibles for quick access
     * Precondtions: both vectors must be initialized
     * Postconditons: the HashTable of Collectibles is built along
     * with a sorted vector of Collectibles
     * @param col : vector of Collectibles
     * @param keys : vector of keys
     */
    void buildInventory(vector<Object*> col, vector<string> keys);

    /*
    displayInventory
    this function displays the whole stores inventory in
    the order based on Coin, ComicBooks, and SportsCards
    along with the number of items of each in inventory
    Preconditions: none
    Postconditions: Inventory is printed out in order
    */
    void displayInventory() const;


    /*
   getCollectible
   this function takes in a string and finds the collectible
   stored in the hash table based on the desc as key
   Preconditions: none
   Postconditions: Collectible pointer is returned for item
   that matches desc
   */
    Object* getCollectible(string desc) const;
};


