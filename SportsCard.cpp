#include "SportsCard.h"
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

/**
* @brief Construct a new SportsCard object
* this function takes in an instance of SportsCard
* and returns a copy
* @param c : instance of SportsCard
*/
SportsCard::SportsCard(const SportsCard& c) {

    player = c.player;
    manufacturer = c.manufacturer;
    count = c.count;
    year = c.year;
    key = c.key;
    typeCol = c.typeCol;
    grade = c.grade;

}

/**
 * @brief Construct a new SportsCard object
 * this function takes in a string and sets the data members
 * of SportsCard based on the string
 * @param desc : whole description of the SportsCard
 */
SportsCard::SportsCard(string desc) 
{
    //S, 1, 1952, Very Good, Mickey Mantle, Topps
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
        player = v[4];
        manufacturer = v[5];
        grade.erase(grade.begin());
        player.erase(player.begin());
        manufacturer.erase(manufacturer.begin());

        key = typeCol + ", " + to_string(year) + 
            ", " + grade + ", " + player + ", " + manufacturer;

}

/**
* getCount
* this function returns the count of the
* Collectible item in inventory
* Preconditons: none
* Postconditions: returns the count
*/
int SportsCard::getCount() const {
    return count;
}

/**
* setCount
* this function sets the count of the
* Collectible item in inventory to c
* Preconditons: c must be valid count number
* Postconditions: sets the count
*/
void SportsCard::setCount(int c) {
    count = c;
}

/**
* getType
* this function returns the type of Collectible
* it is (M, C, S)
* Preconditions: none
* Postconditions: returns the type
*/
string SportsCard::getType() {
    return typeCol;
}


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
bool SportsCard::operator<(const Comparable& colToCompare) const {
    const SportsCard& sc = static_cast<const SportsCard&>(colToCompare);
    //sorted by player, then by year, then by manufacturer, then by grade
    if (this->player < sc.player) {
        return true;
    }
    else if (this->player == sc.player) {
        if (this->year < sc.year) {
            return true;
        }
        else if (this->year == sc.year) {
            if (this->manufacturer < sc.manufacturer) {
                return true;
            }
            else if (this->manufacturer == sc.manufacturer) {
                if (this->grade < sc.grade) {
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
bool SportsCard::operator>(const Comparable& rhs) const {
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
bool SportsCard::operator==(const Comparable& colToCompare) const {
    const SportsCard& sc = static_cast<const SportsCard&>(colToCompare);
    if (key == sc.key) {
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
bool SportsCard::operator!=(const Comparable& rhs) const {
    return !operator==(rhs);
}

/**
    * copy
    * this function returns a copy of the Comparable c
    */
Comparable* SportsCard::copy(const Comparable& c) {
    const SportsCard& s = static_cast<const SportsCard&>(c);
    return new SportsCard(s);
}

/**getKey
* this function returns key for Collectible
*/
string SportsCard::getKey() const {
    return key;
}

/**
 * print
 * this function prints the description
 * of the SportsCard item
 */
void SportsCard::print() const
{
    cout << " Item: ";
    cout << key << " (" << count << " left in store)" << endl;
}
