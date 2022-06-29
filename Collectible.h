#pragma once
/*
 * @file Collectible.h
 * @author Katarina McGaughy
 * Collectible class is an interface for a collectible object that
 * represents a Collectible item that can be sold in the Collectible store.
 * The class stores how many of it are in the Inventory, the year,
 * a string description, and the type. It is sorted based on type
 * and printed in sorted format.
 *
 * Features:
 * -sorts based on type (M, S, C)
 * -prints in sorted order
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Object.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Comparable.h"

class Collectible : public Comparable
{

public:
	/**
	 * @brief Construct a new Collectible object
	 *
	 */
	Collectible() {}


	/**
	 * @brief Destroy the Collectible object
	 *
	 */
	virtual ~Collectible() {}

	/**
	* getCount
	* this function returns the count of the
	* Collectible item in inventory
	* Preconditons: none
	* Postconditions: returns the count
	*/
	virtual int getCount() const = 0;


	/**
	* setCount
	* this function sets the count of the
	* Collectible item in inventory to c
	* Preconditons: c must be valid count number
	* Postconditions: sets the count
	*/
	virtual void setCount(int c) = 0;

	/**
	* getType
	* this function returns the type of Collectible
	* it is (M, C, S)
	* Preconditions: none
	* Postconditions: returns the type
	*/
	virtual string getType() = 0;

	/**
	 * operator<
	 * this function compares two collectible objects
	 * the order is as follows: Coins, ComicBooks, then SportsCards
	 * @param colToCompare
	 * @return true : if the current Collectible comes before
	 * the colToCompare
	 * @return false : if current Collectible comes after colToCompare
	 */
	virtual bool operator<(const Comparable& colToCompare) const = 0;

	/**
	 * operator>
	   * this function returns true if the current object is greater than the
	   * rhs object
	   * Precondition: there is another Collectible object that is initialized
	   * Postcondition: true if the current object is greater than rhs object
	   * @param rhs: Collectible to be compared to current object
	   * @return: true if the current Collectible objects is greater
	   */
	virtual bool operator>(const Comparable& rhs) const = 0;

	/**
	* operator==
	* this function compares two Collectibles for equality
	* Precondition: there is another Collectible object that is initialized
	* Postcondition: true if the two objects are equal
	* @param rhs: Collectible to be compared to current object
	* @return: true if Collectible objects are equal
	*
	*/
	virtual bool operator==(const Comparable& colToCompare) const = 0;

	/**
	* operator!=
	* this function compares two Collectible for inequality
	* Precondition: there is another Collectible object that is initialized
	* Postcondition: true if the two objects are not equal
	* @param colToCompare: Collectible to be compared to current object
	* @return: true if Collectible objects are not the same
	*/
	virtual bool operator!=(const Comparable& rhs) const = 0;

	/**
	* copy
	* this function returns a copy of the Comparable c
	*/
	virtual Comparable* copy(const Comparable& c) = 0;

	/**getKey
	* this function returns key for Collectible
	*/
	virtual string getKey() const = 0;

	/**
	* print
	* this function prints Comparable
	*/
	virtual void print() const = 0;
};


