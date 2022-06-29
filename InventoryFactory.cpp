/*
 * @file Inventory.h
 * @author Katarina McGaughy
 * InventoryFactory creates the following Collectible items based
 * on the string that is read in:
 * Coin, CommicBook, SportsCard
 *
 * Features:
 * -read in string
 * -create Collectible
 *
 * Assumptions:
 * -string is in correct format
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "InventoryFactory.h"


 /**
  * @brief Create a Collectible object
  *
  * @param desc
  * @return Collectible*
  */
Collectible* InventoryFactory::createCollectible(string desc) {
    if (desc[0] == 'M') {
        return new Coin(desc);
    }
    if (desc[0] == 'C') {
        return new ComicBook(desc);
    }
    if (desc[0] == 'S') {
        return new SportsCard(desc);
    }
    cout << "Collectible: ";
    cout << desc << " is not recognized. Try again." << endl;
    return nullptr;
}