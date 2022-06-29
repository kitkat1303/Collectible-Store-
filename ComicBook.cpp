#include "ComicBook.h"
/*
 * @file ComicBook.h
 * @author Katarina McGaughy
 * ComicBook class is a collectible object that
 * represents a ComicBook that can be sold in the Collectible store.
 * The class stores how many of it are in the Inventory, the year,
 * a string description, the grade, and the type.
 * It is sorted based on the following criteria:
 * by publisher, then by title, then by year, then by grade
 *
 * Features:
 * -sorts based by publisher, then by title, then by year, then by grade
 * -prints in sorted order
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Collectible.h"

 /**
  * @brief Construct a new ComicBook object
  * this function takes in an instance of ComicBook
  * and returns a copy
  * @param c : instance of ComicBook
  */
ComicBook::ComicBook(const ComicBook& c) {
	publisher = c.publisher;
	title = c.title;
	count = c.count;
	year = c.year;
	key = c.key;
	typeCol = c.typeCol;
	grade = c.grade;

}


/**
 * @brief Construct a new ComicBook object
 * this function takes in a string and sets the data members
 * of ComicBook based on the string
 * @param desc : whole description of the ComicBook
 */
ComicBook::ComicBook(string desc)
{
	//C, 1, 1938, Mint, Superman, DC 
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
	grade = v[3];
	title = v[4];
	publisher = v[5];
	grade.erase(grade.begin());
	title.erase(title.begin());
	publisher.erase(publisher.begin());

	key = typeCol + ", " + to_string(year) +
		", " + grade + ", " + title + ", " + publisher;
}

/**
* getCount
* this function returns the count of the
* Collectible item in inventory
* Preconditons: none
* Postconditions: returns the count
*/
int ComicBook::getCount() const {
	return count;
}

/**
* setCount
* this function sets the count of the
* Collectible item in inventory to c
* Preconditons: c must be valid count number
* Postconditions: sets the count
*/
void ComicBook::setCount(int c) {
	count = c;
}

/**
* getType
* this function returns the type of Collectible
* it is (M, C, S)
* Preconditions: none
* Postconditions: returns the type
*/
string ComicBook::getType() {
	return typeCol;
}


/**
 * operator<
 * this function compares two ComicBook objects
 * the order is as follows: by publisher, then by title,
 * then by year, then by grade
 * @param cb
 * @return true : if the current ComicBook comes before
 * the cb
 * @return false : if current ComicBook comes after cb
 */
bool ComicBook::operator<(const Comparable& colToCompare) const {
	const ComicBook& cb = static_cast<const ComicBook&>(colToCompare);
	//publisher, then by title, then by year, then by grade
	if (this->publisher < cb.publisher) {
		return true;
	}
	else if (this->publisher == cb.publisher) {
		if (this->title < cb.title) {
			return true;
		}
		else if (this->title == cb.title) {
			if (this->year < cb.year) {
				return true;
			}
			else if (this->year == cb.year) {
				if (this->grade < cb.grade) {
					return true;
				}
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
bool ComicBook::operator>(const Comparable& rhs) const {
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
bool ComicBook::operator==(const Comparable& colToCompare) const {
	const ComicBook& cb = static_cast<const ComicBook&>(colToCompare);
	if (key == cb.key) {
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
bool ComicBook::operator!=(const Comparable& rhs) const {
	return !operator==(rhs);
}

/**
* copy
* this function returns a copy of the Comparable c
*/
Comparable* ComicBook::copy(const Comparable& c) {
	const ComicBook& s = static_cast<const ComicBook&>(c);
	Comparable* ptr = new ComicBook(s);
	return ptr;
}

/**getKey
* this function returns key for Collectible
*/
string ComicBook::getKey() const {
	return key;
}


/**
 * printCollectible
 * this function prints the description
 * of the ComicBook item
 */
void ComicBook::print() const
{
	cout << " Item: ";
	cout << key << " (" << count << " left in store)" << endl;
}
