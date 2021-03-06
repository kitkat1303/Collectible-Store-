/*
 * @file Comparable.h
 * @author Katarina McGaughy
 * Comparable class: The Comparable class is an object that encapsulates a character.
 * The purpose of this class is to store a character as a Comparable object.
 *
 * Features:
 * -store a single char
 * -assignment operator
 * -compare operators (equality, inequality, greater than, and less than) based on
 * ASCII
 * - input and output stream
 *
 * Assumptions:
 * -take in char from istream and store the char
 * -output will be a single char but can be strung together
 * -white space is ignored and capitalization matters
 * -ASCII order determines the order of chars
 *
 * @version 0.1
 * @date 2022-1-12
 *
 * @copyright Copyright (c) 2022
 *
 */

using namespace std;
#include <string>
#include <iostream>
#include "Object.h"
#pragma once

class Comparable : public Object {

	//DONT KNOW IF NEED ISTREAM OR OSTREAM

	/**
	* Overloaded input operator for Comparable class
	* Preconditions: Comparable object character must be initialized
	* Postconditions: the istream character will be assigned to the Comparables
	* private member variable, storedChar
	* @param character: Comparable object
	* @param in: input stream
	* @return: input stream

	friend istream& operator>>(istream& in, Comparable& character);

	/**
	* Overloaded output operator for Comparable class
	* Preconditions: Comparable object character must be initialized
	* Postconditions: the storedChar is sent to the output stream
	* @param character: Comparable object
	* @param os: output stream
	* @return: output stream

	friend ostream& operator<<(ostream& os, Comparable& character);

	*/

public:

	virtual ~Comparable() {}

	/**
	* operator==
	* this function compares two Comparables for equality
	* Precondition: there is another Comparable object that is initialized
	* Postcondition: true if the two objects are equal
	* @param rhs: Comparable to be compared to current object
	* @return: true if Comparable objects are equal
	*
	*/
	virtual bool operator==(const Comparable& rhs) const = 0;

	/**
	* operator!=
	* this function compares two Comparables for inequality
	* Precondition: there is another Comparable object that is initialized
	* Postcondition: true if the two objects are not equal
	* @param rhs: Comparable to be compared to current object
	* @return: true if Comparable objects are not the same
	*/
	virtual bool operator!=(const Comparable& rhs) const = 0;

	/**
	* operator>
	* this function returns true if the current object is greater than the
	* rhs object
	* Precondition: there is another Comparable object that is initialized
	* Postcondition: true if the current object is greater than rhs object
	* @param rhs: Comparable to be compared to current object
	* @return: true if the current Comparable objects is greater
	*/
	virtual bool operator>(const Comparable& rhs) const = 0;

	/**
	* operator<
	* this function returns true if the current object is less than the
	* rhs object
	* Precondition: there is another Comparable object that is initialized
	* Postcondition: true if the current object is less than rhs object
	* @param rhs: Comparable to be compared to current object
	* @return: true if the current Comparable objects is less than rhs
	*/
	virtual bool operator<(const Comparable& rhs) const = 0;

	/**
	* Overloaded assignment operator for Comparable class
	* Preconditions: none
	* Postconditions: the new Comparable object is assigned to the current
	* Comparable object
	* @param rhs: Comparable to be assigned to current object
	* @return: rhs Comparable

	virtual Comparable& operator=(const Comparable& rhs);
	*/

	/**
	* print 
	* this function prints Comparable
	*/
	virtual void print() const = 0;

	/**
	* copy 
	* this function returns a copy of the Comparable c
	*/
	virtual Comparable* copy(const Comparable& c) = 0;


};