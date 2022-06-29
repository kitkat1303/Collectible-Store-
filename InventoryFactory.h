/*
 * @file InventoryFactory.h
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
#pragma once
#include "Inventory.h"
#include "Collectible.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"


class InventoryFactory {
public:

    /**
     * @brief Create a Collectible object
     *
     * @param desc
     * @return Collectible*
     */
    Collectible* createCollectible(string desc);
};