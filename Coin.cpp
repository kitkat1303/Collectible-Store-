#include "Coin.h"
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

 /**
* @brief Construct a new Coin object
* this function takes in an instance of a Coin
* and returns a copy
* @param c : instance of coin
*/
Coin::Coin(const Coin& c) {

	grade = c.grade;
	typeCol = c.typeCol;
	year = c.year;
	count = c.count;
	key = c.key;
	type = c.type;
}

/**
 * @brief Construct a new Coin object
 * this function takes in a string and sets the data members
 * of coin based on the string
 * @param desc : whole description of the coin
 */
Coin::Coin(string desc)
{

	string str(desc);

	vector<string> v;
	stringstream ss(desc);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		v.push_back(substr);
	}

	typeCol = v[0];
	count = stoi(v[1]);
	year = stoi(v[2]);
	grade = stoi(v[3]);
	type = v[4];
	type.erase(type.begin()); //delete space

	key = typeCol + ", " + to_string(year) +
		", " + to_string(grade) + ", " + type;

}

/**
* getCount
* this function returns the count of the
* Collectible item in inventory
* Preconditons: none
* Postconditions: returns the count
*/
int Coin::getCount() const {
	return count;
}

/**
* setCount
* this function sets the count of the
* Collectible item in inventory to c
* Preconditons: c must be valid count number
* Postconditions: sets the count
*/
void Coin::setCount(int c) {
	count = c;
}

/**
* getType
* this function returns the type of Collectible
* it is (M, C, S)
* Preconditions: none
* Postconditions: returns the type
*/
string Coin::getType() {
	return typeCol;
}

/**
 * operator<
 * this function compares two Coin objects
 * the order is as follows: type, then by year, then by grade
 * @param coin
 * @return true : if the current Coin comes before
 * the coin
 * @return false : if current Coin comes after coin
 */
bool Coin::operator<(const Comparable& colToCompare) const
{
	const Coin& coin = static_cast<const Coin&>(colToCompare);
	//sorted by greatest in heap so want 3 before 10
	if (this->type < coin.type) {
		return true;
	}
	else if (this->type == coin.type) {
		if (this->year < coin.year) {
			return true;
		}
		else if (this->year == coin.year) {
			if (this->grade < coin.grade) {
				return true;
			}
		}
	}
	return false;
}

/**
* operator>
* this function returns true if the current object is greater than the
* rhs object
* Precondition: there is another Collectible object that is initialized
* Postcondition: true if the current object is greater than rhs object
* @param rhs: Collectible to be compared to current object
* @return: true if the current Collectible objects is greater
*/
bool Coin::operator>(const Comparable& rhs) const {
	return !operator<(rhs);
}

/**
* operator==
* this function compares two Collectibles for equality
* Precondition: there is another Collectible object that is initialized
* Postcondition: true if the two objects are equal
* @param rhs: Collectible to be compared to current object
* @return: true if Collectible objects are equal
*
*/
bool Coin::operator==(const Comparable& colToCompare) const {
	const Coin& coin = static_cast<const Coin&>(colToCompare);
	if (key == coin.key) {
		return true;
	}
	return false;
}

/**
* operator!=
* this function compares two Collectible for inequality
* Precondition: there is another Collectible object that is initialized
* Postcondition: true if the two objects are not equal
* @param colToCompare: Collectible to be compared to current object
* @return: true if Collectible objects are not the same
*/
bool Coin::operator!=(const Comparable& rhs) const {
	return !operator==(rhs);
}

/**
* copy
* this function returns a copy of the Comparable c
*/
Comparable* Coin::copy(const Comparable& c) {
	const Coin& cust = static_cast<const Coin&>(c);
	Comparable* ptr = new Coin(cust);
	return ptr;
}

/**getKey
* this function returns key for Collectible
*/
string Coin::getKey() const {
	return key;
}

/**
 * print
 * this function prints the description
 * of the Coin item
 */
void Coin::print() const
{
	cout << " Item: ";
	cout << key << " (" << count << " left in store)" << endl;
}

