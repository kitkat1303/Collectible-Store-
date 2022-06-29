#pragma once
/*
 * @file CollectibleStore.h
 * @author Katarina McGaughy
 * CollectibleStore is a type of Store that contains a list of
 * Inventory, Customers, and Commands that the store can do like:
 * Buy, Sell, Display, DisplayCustomers, and DisplayHistory
 *
 * Features:
 * -read in information from file
 * -store customer, commands, and inventory from files
 * -subclass of Store
 *
 * Assumptions:
 * -file is in correct format
 *
 * @version 0.1
 * @date 2022-2-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Store.h"
#include <vector>
#include "CustomerList.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Inventory.h"
#include <fstream>
#include "InventoryFactory.h"

class CollectibleStore : public Store {

private:

    //stores ordered list of customers and hashtable of customers
    CustomerList* cList = nullptr;
    //stores ordered list of inventory
    Inventory* iList = nullptr; 
    //creates inventory items
    InventoryFactory i;

    /*Command class is an interface for various types of commands
    * that can be performed on the CollectibleStore class
    */
    class Command : public Object {
    protected:
        string command;
        bool valid = false;
    public:

     /**
      * @brief Construct a new Command object
      * takes in a string that represents command
      * @param commandSpecs : sets this to command member variables
      */
        Command(string commandSpecs) : command(commandSpecs) {}

        /**
         * Execute
         * this function reads in commands from a file and
         * initializes them via the CommandFactory and
         * stores them in the commands vector
         * Preconditions: file must be in the correct format
         * Postconditions: Command executed
         *
         * @param file : file of commands
        */
        virtual void Execute(CustomerList* cList, Inventory* iList) = 0;

    };

    /* Buy is a type of Command that will create a transaction via
    * the Customer class, which also updates inventory
    S*/
    class Buy : public Command {
    public:

      /**
      * @brief Construct a new Buy object
      * takes in a string that represents command
      * @param commandSpecs : sets this to command member variables
      */
        Buy(string commandSpecs) : Command(commandSpecs) {}

        /**Execute
        * this functions takes in a CustomerList and InventoryList
        * and buys a Collectible item from a customer
        * Preconditions: CustomerList and InventoryList must be initialized
        * Postconditions: if the customer and collectible exist and the
        * customer has the collectible, the item is bought and added to
        * inventory of the store and the transactions for customer is updated.
        * If the customer or collectible do not exist, an error message is displayed
        */
        void Execute(CustomerList* cList, Inventory* iList);

    };

    /*Sell is a type of Command that will create a transaction via
    * the Customer class, which also updates inventoryS
    */
    class Sell : public Command {
    public:

      /**
      * @brief Construct a new Sell object
      * takes in a string that represents command
      * @param commandSpecs : sets this to command member variables
      */
        Sell(string commandSpecs) : Command(commandSpecs) {}

        /**Execute
         * this functions takes in a CustomerList and InventoryList
         * and sells a Collectible item to a customer
         * Preconditions: CustomerList and InventoryList must be initialized
         * Postconditions: if the customer and collectible exist and the
         * inventory count of the collectible is not 0, a purchase is made
         * by the customer and stored in transactions for the customer
         * if the customer or collectible do not exist, an error message is displayed
         */
        void Execute(CustomerList* cList, Inventory* iList);

    };

    /*Display is a type of Command that will display the entire inventory of
    * the store via the Inventory class
    */
    class Display : public Command {

    public:

      /**
      * @brief Construct a new Display object
      * takes in a string that represents command
      * @param commandSpecs : sets this to command member variables
      */
        Display(string commandSpecs) : Command(commandSpecs) {}

        /**Execute
        * this functions takes in a CustomerList and InventoryList
        * and sells a Collectible item to a customer
        * Preconditions: CustomerList and InventoryList must be initialized
        * Postconditions: the entire stored inventory is displayed
        */
        void Execute(CustomerList* cList, Inventory* iList);

    };

    /*CustomerDisplay is a type of Command that will display all transactions for 
    a single customer via the CustomerList class
     */
    class CustomerDisplay : public Command {
    public:

      /**
      * @brief Construct a new CustomerDisplay object
      * takes in a string that represents command
      * @param commandSpecs : sets this to command member variables
      */
        CustomerDisplay(string commandSpecs) : Command(commandSpecs) {}

        /**Execute
        * this functions takes in a CustomerList and InventoryList
        * and sells a Collectible item to a customer
        * Preconditions: CustomerList and InventoryList must be initialized
        * Postconditions: if the customer exists, the transactions for the customer
        * are displayed, if the customer does not exist, an error message is displayed
        */
        void Execute(CustomerList* cList, Inventory* iList);

    };

    /* History is a type of Command that will display all customers
     * in alphabetical order and print them out along with all of
     * their transactions
     */
    class History : public Command {

    public:

        /**
      * @brief Construct a new History object
      * takes in a string that represents command
      * @param commandSpecs : sets this to command member variables
      */
        History(string commandSpecs) : Command(commandSpecs) {}

        /**Execute
        * this functions takes in a CustomerList and InventoryList
        * and sells a Collectible item to a customer
        * Preconditions: CustomerList and InventoryList must be initialized
        * Postconditions: the entire customer list is printed in alphabetical order and
        * their transactions are displayed
        */
        void Execute(CustomerList* cList, Inventory* iList);

    };

    /* CommandFactory creates the following commands based on the string that* is read in :
    * Buy, Sell, Display, DisplayCustomers, and DisplayHistory
    *
    * Features :
    *-read in string
    * -create commands
    */
    class CommandFactory
    {
    public:
        /**
         * createCommand
         * Create a Command object
         *
         * @param desc : string that is read in from file
         * @return Command* : new Command object
         */
        CollectibleStore::Command* createCommand(string desc);
    };

    //instance of command factory 
    CommandFactory c;  

    /**
     * @brief executeCommands
     * this function takes in a vector of commands
     * Preconditions: vector of commands must be initialized
     * Postconditions: commands are executed
     */
    void executeCommands(vector<Command*> commandList);


public:

    /**
     * Constructor
     * construct a new Collectible Store object
     * sets the commands vectors to nullptr
     * initializes the cList and iList **do these need to be pointers??
     *
     */
    CollectibleStore();

    /**
     * Destructor
     * deallocate all vector of commands
     * destructors for CustomerList and Inventory should handle their memory
     */
    ~CollectibleStore();

    /**
     * @brief initializeInventory
     * reads in a file line by line and initializes collectible items
     * and creates a hash table of items as well as a sorted list of
     * items in the Inventory class
     * Preconditions: file must exist
     * Postconditions: Inventory is built
    */
    void initializeInventory(ifstream& infile);


    /**
     * @brief initializeCustomers
     * reads in a file line by line and initializes customers
     * and creates a hash table of customers with their ID as the key
     *  as well as creates a sorted list of customers (alphabetical)
     * in the CustomerList class
     * Preconditions: file must exist
     * Postconditions: CustomerList is built
     */
    void initializeCustomers(ifstream& infile);

    /**
     * getCommands
     * this function reads in commands from a file and
     * initializes them via the CommandFactory and
     * stores them in the commands vector
     * Preconditions: file must be in the correct format
     * Postconditions: commands vector is filled
     *
     * @param file : file of commands
    */
    void getCommands(ifstream& infile);


};
