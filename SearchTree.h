/*
 * @file SearchTree.h
 * @author Katarina McGaughy
 * SearchTree class: The SearchTree class takes in a Comparable Object and
 * creates a BST based on Comparable objects and orderes them based on ASCII.
 * The purpose of this class is to store Comparable objects in ASCII order and keep
 * count of the number of times a character is found in a file.
 *
 * Features:
 * -store Comparables in a BST
 * -copy constructor
 * -assignment operator
 * -equality and inequality operator overload
 * -insert, delete, retrieve, get the height and depth of a node, and delete all contents
 * of BST
 * -output stream (frequency of character and characters inorder)
 *
 * Assumptions:
 * -create a BST from Comparables
 * -output will be inorder
 * -ASCII order determines the order of BST
 *
 * @version 0.1
 * @date 2022-1-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "Comparable.h"
using namespace std;
#include <vector>

class SearchTree
{

private:
	/**
	* Node struct contains a pointer to a Comparable object called data, a pointer to
	* right child node and left child node, and a count for the frequency of the Comparable
	*/
	struct Node {

		//pointer to Comparable object 
		Comparable* data = nullptr;

		//pointer to right child
		Node* rightChild = nullptr;

		//pointer to left child
		Node* leftChild = nullptr;

		//count of number of times Comparable appears
		int count = 0;
	};

	//pointer to root of BST
	Node* root_;

	//keeps track of the number of nodes in the BST 
	int numberOfNodes;


	/**
	 * comparingHelper
	 * this is a recursive function that compares two search trees
	 * and returns true if they are the same and false if they are not
	 * Preconditions: none
	 * Postconditios: returns true if they are the same and false if they are not
	 * @param otherRoot: pointer to root of this SearchTree
	 * @param thisRoot: pointer to root of other SearchTree
	 * @return: returns true if they are the same and false if they are not
	 */
	bool comparingHelper(Node* otherRoot, Node* thisRoot) const;

	/**
	 * copyHelper
	 * this is a recursive function that copies the tree from copyRoot to
	 * the current search tree
	 * Preconditions: none
	 * Postconditios: SearchTree assgined with values from the tree to be copied
	 * @param copyRoot: pointer to root of the SearchTree to be copied
	 * @param thisRoot: pointer to root of other SearchTree
	 */
	void copyHelper(Node* copyRoot, Node*& thisRoot) const;

	/**
	 * insertHelper
	 * this is a recursive function that inserts a node in the correct place
	 * in the BST if it is new data and returns true, it returns false if the data
	 * already exists and increments count
	 * Preconditions: root can not be nullptr
	 * Postconditios: returns true if the item is inserted succesfully
	 * and false if the Search tree already contains data
	 * @param root: pointer to root of SearchTree
	 * @param data: pointer to a Comparable object
	 * @return: true if the node with data is inserted and false
	 * if the data already exists in the tree
	 */
	bool insertHelper(Node*& root, Comparable* data);

	/**
	  * deleteNode
	  * this is a recursive function that finds the correct node
	  * and decrements count by one and if the count is 0, it will call
	  * deleteRoot and decrement number of nodes by one
	  * Preconditions: none
	  * Postconditios: returns true if the item is deleted succesfully
	  * and false if the Search tree does not contain data
	  * @param root: pointer to root of SearchTree
	  * @param data: pointer to a Comparable object
	  * @return: true if the node with data is deleted and false
	  * if the data is not found in the tree
	  */
	bool deleteNode(Node*& root, const Comparable& data);

	/**
	 * deleteRoot
	 * this is a recursive function deletes the root if the node has either
	 * no children or one child. if the node has two children, the function calls
	 * findAndDeleteMostLeft() in order to keep the order of the BST
	 * Preconditions: root can not be nullptr
	 * Postconditios: deletes the node and retains BST order
	 * @param root: pointer to root of SearchTree
	 */
	void deleteRoot(Node*& root);

	/**
	 * findAndDeleteMostLeft
	 * this is a recursive function that finds the greatest value node
	 * in the left subtree and deletes it
	 * Preconditions: root can not be nullptr
	 * Postconditios: returns the data that will replace the deleted node
	 * @param root: pointer to root of SearchTree
	 * @return: data of node that will replace the deleted nodes place
	 */
	Comparable* findAndDeleteMostLeft(Node*& root);

	/**
	 * retrieveHelper
	 * this is a recursive function that finds the node with the data
	 * enetered and returns the data
	 * Preconditions: none
	 * Postconditios: returns the data if found and if not returns nullptr
	 * @param root: pointer to root of SearchTree
	 * @param data: pointer to a Comparable object
	 * @return: returns the data if found and if not returns nullptr
	 */
	const Comparable* retrieveHelper(const Node* root, const Comparable& data) const;

	/**
	* makeEmptyHelper
	* this recursive function deletes all nodes in
	* SearchTree
	* Preconditions: none
	* Postconditios: empty SearchTree
	* @param root: pointer to root of SearchTree
	* @param data: pointer to a Comparable object
	*/
	void makeEmptyHelper(Node*& root);

	/**
	* inorderPrint
	* this function takes in root of SearchTree and recursively prints the
	* data and count in inorder
	* Preconditions: none
	* Postconditions: the SearchTree is printed in inorder
	* @param root: pointer to root of SearchTree
	*/
	void inorderPrint(Node* root) const;

	/**
	* createVector
	* this function takes in a root of SearchTree and stores 
	* all elements in the tree in a vector and returns the vector
	* Preconditions: none 
	* Postconditions: return a vector of Comparables
	*/
	vector<Comparable*> createVector(Node* root) const;


public:

	/**
	* constructor
	* this function initializes a SearchTree and the sets the
	* root_ to nullptr and numberOfNodes to 0
	* Preconditions: none
	* Postconditios: root_ is set to nullptr and numberOfNodes is set to 0
	*/
	SearchTree();

	/**
	 * desctructor
	 * this function deletes are nodes from SearchTree
	 * Preconditions: none
	 * Postconditios: SearchTree is deleted
	 */
	~SearchTree();

	/**
	 * copy constructor
	 * this function initializes a new SearchTree with the treeToBeCopied
	 * values via the copyHelper function
	 * Preconditions: none
	 * Postconditios: a new search tree is initialized with the same values
	 * as the rhs tree
	 * @param treeToBeCopied: SearchTree to be copied
	 */
	SearchTree(const SearchTree& copyTree);

	/**
	 * operator=
	 * this function clears the current tree if it is not the same as the rhs
	 * tree and then assigns the rhs tree to the current tree via copyHelper()
	 * Preconditions: none
	 * Postconditios: a new search tree is initialized with the same values
	 * as the rhs tree
	 * @param rhs: right hand side search tree
	 */
	const SearchTree& operator=(const SearchTree& rhs);

	/**
	 * operator==
	 * this function calls compareToHelper and returns true if compareToHelper
	 * returns true
	 * Preconditions: none
	 * Postconditios: returns true if the trees are the same and false or else
	 * @param rhs: right hand side search tree
	 * @return: returns true if the trees are the same and false or else
	 */
	bool operator==(const SearchTree& rhs) const;

	/**
	 * operator!=
	 * this function calls compareToHelper and returns true if compareToHelper
	 * returns false
	 * Preconditions: none
	 * Postconditios: returns true if they are not the same tree and
	 * false if they are
	 * @param rhs: right hand side search tree
	 * @return: returns true if they are not the same tree and
	 * false if they are
	 */
	bool operator!=(const SearchTree& rhs) const;

	/**
	 * insert
	 * this function calls insertHelper that inserts a node in the correct place
	 * in the BST if it is new data and returns true, it returns false if the data
	 * already exists and increments count
	 * Preconditions: none
	 * Postconditios: returns true if the item is inserted succesfully
	 * and false if the Search tree already contains data
	 * @param root: pointer to root of SearchTree
	 * @param data: pointer to a Comparable object
	 * @return: true if the node with data is inserted and false
	 * if the data already exists in the tree
	 */
	bool insert(Comparable* data);

	/**
	 * remove
	 * this function calls deleteNode which either decrements count
	 * of Comparable or deletes node if the count is 0.
	 * Preconditions: none
	 * Postconditios: returns true if the item is deleted succesfully
	 * and false if the Search tree does not contain the data
	 * @param data: pointer to a Comparable object
	 * @return: true if the node with data is deleted and false
	 * if the data is not found in the tree
	 */
	bool remove(const Comparable& data);

	/**
	 * retrieve
	 * this function calls retrieveHelper in order to return the data that is
	 * entered in the function
	 * Preconditions: none
	 * Postconditios: returns the data if found and if not returns nullptr
	 * @param data: pointer to a Comparable object
	 * @return: returns the data if found and if not returns nullptr
	 */
	const Comparable* retrieve(const Comparable& data) const;

	/**
	 * makeEmpty
	 * this function calls makeEmptyHelper and deletes all nodes in
	 * SearchTree
	 * Preconditions: none
	 * Postconditios: empty SearchTree
	 * @param root: pointer to root of SearchTree
	 */
	void makeEmpty();

	/**
	* print
	* prints the tree in order
	* Precondtions: none
	* Postconidtions: prints the tree's contents
	*/
	void print() const;

	/**
	* createVector
	* this function calls the createVector function
	* which takes in a root of SearchTree and stores
	* all elements in the tree in a vector and returns the vector
	* Preconditions: none
	* Postconditions: return a vector of Comparables
	*/
	vector<Comparable*> traverseInOrder() const;

};


