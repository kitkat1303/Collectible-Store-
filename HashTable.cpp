#include "HashTable.h"

//create a constructor for customer that takes in size (1000) and takes in string of customerID

/*
 * @file HashTable.h
 * @author Katarina McGaughy
 * HashTable class creates a hash table of objects with strings as keys.
 *
 *
 * Features:
 * -insert
 * -remove
 * -getObject
 * -clear
 * -isEmpty
 * -resizeArray
 * -hash
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */


 /**
  * hash
  * this function takes in a key and then returns
  * an index where the Object will be inserted
  * @param key : string representing the key
  * @return int : index
  */
int HashTable::hash(string key) const
{
    int index = 0;
    int in = 0;
    for (int i = 0; i < key.length(); i++) {
        in += key[i];
    }

    index = (in % size);

    if (index < 0) {
        index += size;
    }

    int i = 1;
    while (hashTable[index] != nullptr) {
        index = (in + i) % size;
        i++;
    }

    return index;

}


/**
 * @brief Construct a new Hash Table object
 * Constructor takes in vector of Object pointers and auto keys
 * and creates a hashtable
 * if the number of elements in hashObjects is greater than 1/2
 * the size of the hashTable array, the array is resized
 * if keys are ints then a seperate hash function is called
 * @param hashObjects : vector of Object pointers
 * @param keys : vector of keys
 */
HashTable::HashTable(vector<Object*> hashObjects, vector<string> keys) {

    build(hashObjects, keys);
}

/**
 * @brief Destroy the Hash Table object
 *
 */
HashTable::~HashTable() {
    clear();
}


/**
* build
* this function takes in vector of Object pointersand auto keys
* and creates a hashtable
* if the number of elements in hashObjects is greater than 1 / 2
* the size of the hashTable array, the array is resized
* if keys are ints then a seperate hash function is called
* @param hashObjects : vector of Object pointers
* @param keys : vector of keys
*/
void HashTable::build(vector<Object*> hashObjects, vector<string> keys) {
    numItems = hashObjects.size();
    size = numItems * 2;
    hashTable = vector<Item*>(size, nullptr);
    //initialize new Item object to hold hashObject and key
    for (int i = 0; i < numItems; i++) {
            Item* newItem = new Item(); //memory leak
            newItem->value = hashObjects[i];
            newItem->key = keys[i];
            //insert into table based on hash index
            hashTable[hash(newItem->key)] = newItem;
    }

    for (int i = 0; i < hashObjects.size(); i++) {
        hashObjects[i] = nullptr;
    }
}


/**
 * clear
 * this function clears the entire HashTable
 * Preconditons: none
 * Postconditions: empty HashTable
 *
 */
void HashTable::clear() {
    for (int i = 0; i < numItems; i++) {
        if (hashTable[i] != nullptr) {
            if (hashTable[i]->value != nullptr) {
                //delete value stored in Item
                delete hashTable[i]->value;
            }
            //delete Item
            delete hashTable[i];
        }
    }
    hashTable.clear();
}

/**
 * @brief Get the Value object
 *
 * @param key
 * @return Object*
 */
Object* HashTable::getValue(string key) const {
    // call the hash function on the key and then go to
    Item* item = hashTable[hash(key)];
    if (item == nullptr) {
        return nullptr;
    } 
    return item->value;
    
}


/**
 * isEmpty
 * Preconditions: none
 * Postconditions: true if there are no items in hashTable, or else
 * false
 * @return true : if there are no items in HashTable
 * @return false : if there is at least one item in the HashTable
 */
bool HashTable::isEmpty() const {
    return numItems == 0;
}

