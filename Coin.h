#pragma once
/*
 * @file Coin.h
 * @author Katarina McGaughy
 * Coin class is a collectible object that
 * represents a coin that can be sold in the Collectible store.
 * The class stores how many of it are in the Inventory, the year,
 * a string description, the grade, and the type.
 * It is sorted based on the following criteria:
 * by type, then by year, then by grade
 *
 * Features:
 * -sorts based on type, then by year, then by grade
 * -prints in sorted order
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Collectible.h"


class Coin : public Collectible
{
private:
    string typeCol = "";
    int count = 0;
    int grade = 0; // the grade for the coin
    string type = "";
    int year = 0;
    string key = "";


public:
    /**
     * @brief Construct a new Coin object
     *
     */
    Coin() {
    }

    /**
     * @brief Construct a new Coin object
     * this function takes in an instance of a Coin 
     * and returns a copy
     * @param c : instance of coin
     */
    Coin(const Coin& c);

    /**
     * @brief Construct a new Coin object
     * this function takes in a string and sets the data members
     * of coin based on the string
     * @param desc : whole description of the coin
     */
    Coin(string desc);

    /**
     * @brief Destroy the Coin object
     *
     */
    ~Coin() {}


    /**
    * getCount
    * this function returns the count of the
    * Collectible item in inventory
    * Preconditons: none
    * Postconditions: returns the count
    */
    int getCount() const override;

    /**
    * setCount
    * this function sets the count of the
    * Collectible item in inventory to c
    * Preconditons: c must be valid count number
    * Postconditions: sets the count
    */
    void setCount(int c) override;

    /**
    * getType
    * this function returns the type of Collectible
    * it is (M, C, S)
    * Preconditions: none
    * Postconditions: returns the type
    */
    string getType() override;

    /**
     * operator<
     * this function compares two Coin objects
     * the order is as follows: type, then by year, then by grade
     * @param coin
     * @return true : if the current Coin comes before
     * the coin
     * @return false : if current Coin comes after coin
     */
    bool operator<(const Comparable& c) const override;

    /**
     * operator>
    * this function returns true if the current object is greater than the
    * rhs object
    * Precondition: there is another Collectible object that is initialized
    * Postcondition: true if the current object is greater than rhs object
    * @param rhs: Collectible to be compared to current object
    * @return: true if the current Collectible objects is greater
    */
    bool operator>(const Comparable& rhs) const override;

    /**
    * operator==
    * this function compares two Collectibles for equality
    * Precondition: there is another Collectible object that is initialized
    * Postcondition: true if the two objects are equal
    * @param rhs: Collectible to be compared to current object
    * @return: true if Collectible objects are equal
    *
    */
    bool operator==(const Comparable& colToCompare) const override;

    /**
    * operator!=
    * this function compares two Collectible for inequality
    * Precondition: there is another Collectible object that is initialized
    * Postcondition: true if the two objects are not equal
    * @param colToCompare: Collectible to be compared to current object
    * @return: true if Collectible objects are not the same
    */
    bool operator!=(const Comparable& rhs) const override;

    /**
    * copy
    * this function returns a copy of the Comparable c
    */
    Comparable* copy(const Comparable& c) override;

    /**getKey
    * this function returns key for Collectible
    */
    string getKey() const override;

    /**
     * print
     * this function prints the description
     * of the Coin item
     */
    void print() const override;
};

