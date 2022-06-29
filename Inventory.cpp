#include "Inventory.h"
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


 /**
  * buildSortedList
  * this function takes in an array of Collectible pointers
  * and builds a sorted vector of them
  * Preconditons: inventory array must be initialized
  * Postconditions: orderedInventoryList is updated
  * @param inventory : vector of Collectible arrays
  */
void Inventory::buildSortedList(vector<Object*>& inventory)
{
    for (int i = 0; i < inventory.size(); i++) {
        Collectible* col = dynamic_cast<Collectible*>(inventory[i]);
        //int numItems = 0;
            if (col->getType() == "M") {
                //numItems = col->getCount();
                //while (numItems > 0) {
                    orderedCoins->insert(col);
                   // numItems--;
               // }
            }
            else if (col->getType() == "S") {
                orderedSportsCards->insert(col);
            }
            else if (col->getType() == "C") {
                orderedComicBooks->insert(col);
            }
        else {
            cout << "Invalid Inventory item. Will not add to inventory." << endl;
        }
    }

    orderedInventoryList.push_back(orderedCoins);
    orderedInventoryList.push_back(orderedComicBooks);
    orderedInventoryList.push_back(orderedSportsCards);

}


/**
 * @brief Construct a new Inventory object
 *
 */
Inventory::Inventory() {
    orderedCoins = new SearchTree();
    orderedComicBooks = new SearchTree();
    orderedSportsCards = new SearchTree();
}

/**
 * @brief Destroy the Inventory object
 *
 */
Inventory::~Inventory() {

    for (int i = 0; i < orderedInventoryList.size(); i++) {
        if (orderedInventoryList[i] != nullptr) {
            delete orderedInventoryList[i];
        }
    }

    orderedInventoryList.clear();

    //set pointers to nullptr
    orderedCoins = nullptr;
    orderedSportsCards = nullptr;
    orderedComicBooks = nullptr;

    
}

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
void Inventory::buildInventory(vector<Object*> col, vector<string> keys)
{
    buildSortedList(col); //via SearchTree
    inventoryList.build(col, keys); // create Hashtable of customers

}

/*
displayInventory
this function displays the whole stores inventory in
the order based on Coin, ComicBooks, and SportsCards
along with the number of items of each in inventory
Preconditions: none
Postconditions: Inventory is printed out in order
*/
void Inventory::displayInventory() const
{
    for (int i = 0; i < orderedInventoryList.size(); i++) {
        orderedInventoryList[i]->print();
    }

}

/*
getCollectible
this function takes in a string and finds the collectible
stored in the hash table based on the desc as key
Preconditions: none
Postconditions: Collectible pointer is returned for item
that matches desc
*/
Object* Inventory::getCollectible(string desc) const {
   return inventoryList.getValue(desc);

}


