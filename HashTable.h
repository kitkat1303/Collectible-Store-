#pragma once
#include <vector>
#include "Object.h"
#include <string>
using namespace std;
#include <iostream>
/*
 * @file HashTable.h
 * @author Katarina McGaughy
 * HashTable class creates a hash table of objects with strings as keys.
 *
 *
 * Features:
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


class HashTable
{

private:
    /**
     * Item struct holds a string key and a pointer
     * to an Object
     *
     */
    struct Item
    {

        string key = "";
        Object* value = nullptr;
    };

    vector<Item*> hashTable;     // hashtable storing items
    int size = 0;
    int numItems = 0;


    /**
     * hash
     * this function takes in a key and then returns
     * an index where the Object will be inserted
     * @param key : string representing the key
     * @return int : index
     */
    int hash(string key) const;

public:

    HashTable() {
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
    HashTable(vector<Object*> hashObjects, vector<string> keys);

    /**
     * @brief Destroy the Hash Table object
     *
     */
    ~HashTable();

    void build(vector<Object*> hashObjects, vector<string> keys);

    /**
     * clear
     * this function clears the entire HashTable
     * Preconditons: none
     * Postconditions: empty HashTable
     *
     */
    void clear();

    /**
     * @brief Get the Value object
     *
     * @param key
     * @return Object*
     */
    Object* getValue(string key) const; // call the hash function on the key and then go to
    // given index


    /**
     * isEmpty
     * Preconditions: none
     * Postconditions: true if there are no items in hashTable, or else
     * false
     * @return true : if there are no items in HashTable
     * @return false : if there is at least one item in the HashTable
     */
    bool isEmpty() const;
};

