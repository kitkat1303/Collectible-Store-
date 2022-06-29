#include "Collectible.h"
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

 /**
  * @brief Construct a new Collectible object
  *
  */
Collectible::Collectible() {}

Collectible::~Collectible() {

}

/**
 * @brief Construct a new Collectible object
 *
 * @param fullDescription
 */
Collectible::Collectible(string fullDescription)
{
    //M, 3, 2001, 65, Lincoln Cent
    type = fullDescription[0];
   
}


char Collectible::getType() {
    return type;
}





