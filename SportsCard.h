#pragma once
/*
 * @file SportsCard.h
 * @author Katarina McGaughy
 * SportsCard class is a collectible object that
 * represents a sports card that can be sold in the Collectible store.
 * The class stores how many of it are in the Inventory, the year,
 * a string description, the grade, the manufacturer, the player
 * and the type. It is sorted based on the following criteria:
 * by player, then by year, then by manufacturer, then by grade
 *
 * Features:
 * -sorts based by player, then by year, then by manufacturer,
 * then by grade
 * -prints in sorted order
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "SportsCard.h"
#include "Collectible.h"

class SportsCard : public Collectible
{
private:

    string typeCol = "";
    int count = 0;
    string player = "";
    int year = 0;
    string manufacturer = "";
    string grade = ""; 
    string key = "";


public:

    /**
     * @brief Construct a new Sports Card object
     *
     */
    SportsCard()
    {
    }

    /**
     * @brief Construct a new SportsCard object
     * this function takes in an instance of SportsCard
     * and returns a copy
     * @param c : instance of SportsCard
     */
    SportsCard(const SportsCard& c);

    /**
     * @brief Construct a new SportsCard object
     * this function takes in a string and sets the data members
     * of SportsCard based on the string
     * @param desc : whole description of the SportsCard
     */
    SportsCard(string desc);

    /**
     * @brief Destroy the Sports Card object
     *
     */
    ~SportsCard() {}


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
     * this function compares two SportsCard objects
     * the order is as follows: by player, then by year, then by
     *  manufacturer, then by grade
     * @param sc
     * @return true : if the current SportsCard comes before
     * the sc
     * @return false : if current SportsCard comes after sc
     */
    bool operator<(const Comparable& colToCompare) const override;

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
     * printCollectible
     * this function prints the description
     * of the SportsCard item
     */
    void print() const override;
};

