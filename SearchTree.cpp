/*
 * @file SearchTree.cpp
 * @author Katarina McGaughy
 * SearchTree class implementation: The SearchTree class takes in a Comparable Object and
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
#include "SearchTree.h"
# include <cassert>
using namespace std;

/**
 * constructor
 * this function initializes a SearchTree and the sets the
 * root_ to nullptr and numberOfNodes to 0
 * Preconditions: none
 * Postconditios: root_ is set to nullptr and numberOfNodes is set to 0
 */
SearchTree::SearchTree() : root_(nullptr), numberOfNodes(0) {

}

/**
 * desctructor
 * this function deletes are nodes from SearchTree
 * Preconditions: none
 * Postconditios: SearchTree is deleted
 */
SearchTree::~SearchTree() {
	makeEmpty();
	numberOfNodes = 0;
}

/**
 * copy constructor
 * this function initializes a new SearchTree with the treeToBeCopied
 * values via the copyHelper function
 * Preconditions: none
 * Postconditios: a new search tree is initialized with the same values
 * as the rhs tree
 * @param treeToBeCopied: SearchTree to be copied
 */
SearchTree::SearchTree(const SearchTree& treeToBeCopied) {
	//set number of nodes 
	this->numberOfNodes = treeToBeCopied.numberOfNodes;
	this->root_ = nullptr;
	//copy tree
	copyHelper(treeToBeCopied.root_, this->root_);

}

/**
 * operator=
 * this function clears the current tree if it is not the same as the rhs
 * tree and then assigns the rhs tree to the current tree via copyHelper()
 * Preconditions: none
 * Postconditios: a new search tree is initialized with the same values
 * as the rhs tree
 * @param rhs: right hand side search tree
 */
const SearchTree& SearchTree::operator=(const SearchTree& rhs) {
	//if the trees are not the same then delete current tree and replace
	if (this != &rhs) {
		//delete tree
		this->makeEmpty();
		//assign number of nodes 
		this->numberOfNodes = rhs.numberOfNodes;
		//copy tree
		copyHelper(rhs.root_, this->root_);
	}
	return *this;
}

/**
 * copyHelper
 * this is a recursive function that copies the tree from copyRoot to
 * the current search tree
 * Preconditions: none
 * Postconditios: SearchTree assgined with values from the tree to be copied
 * @param copyRoot: pointer to root of the SearchTree to be copied
 * @param thisRoot: pointer to root of other SearchTree
 */
void SearchTree::copyHelper(Node* copyRoot, Node*& thisRoot) const{

	if (copyRoot != nullptr) {
		thisRoot = new Node();
		//thisRoot->data = new Comparable; 
		thisRoot->data = thisRoot->data->copy(*copyRoot->data);
		//*thisRoot->data = *copyRoot->data;
		thisRoot->count = copyRoot->count;
		copyHelper(copyRoot->leftChild, thisRoot->leftChild);
		copyHelper(copyRoot->rightChild, thisRoot->rightChild);
	}
	else {
		thisRoot = nullptr;
	}
}

/**
 * operator==
 * this function calls compareToHelper and returns true if compareToHelper
 * returns true
 * Preconditions: none
 * Postconditios: returns true if the trees are the same and false or else
 * @param rhs: right hand side search tree
 * @return: returns true if the trees are the same and false or else
 */
bool SearchTree::operator==(const SearchTree& rhs) const {
	return comparingHelper(rhs.root_, this->root_);
}

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
bool SearchTree::operator!=(const SearchTree& rhs) const {
	return !comparingHelper(rhs.root_, this->root_);
}


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
bool SearchTree::comparingHelper(Node* otherRoot, Node* thisRoot) const {
	//if both roots are nullptr return true 
	if (otherRoot == nullptr && thisRoot == nullptr) {
		return true;
	}
	//if roots are not the same then retuen false 
	else if (otherRoot == nullptr && thisRoot != nullptr) {
		return false;
	}
	else if (otherRoot != nullptr && thisRoot == nullptr) {
		return false;
	}
	//if both roots are not nullptr 
	else {
		//return true if the data and count are the same for the nodes
		if (*otherRoot->data == *thisRoot->data &&
			otherRoot->count == thisRoot->count &&
			comparingHelper(otherRoot->leftChild, thisRoot->leftChild) &&
			comparingHelper(otherRoot->rightChild, thisRoot->rightChild)) {
			return true;
		}
		else {
			return false;
		}
	}
}

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
bool SearchTree::insert(Comparable* data) {
	//if the root_ is nullptr then create a new node with the data 
	if (root_ == nullptr) {
		root_ = new Node();
		root_->data = data;
		root_->leftChild = nullptr;
		root_->rightChild = nullptr;
		//increment count 
		root_->count++;
		this->numberOfNodes++;
		return true;
	}
	//if root_ is not nullptr then call insertHelper
	else {
		return insertHelper(root_, data);
	}

}

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
bool SearchTree::insertHelper(Node*& root, Comparable* data) {
	//if root is data then increment count of node and return false
	if (*root->data == *data) {
		root->count++;
		return false;
	}
	//if data is less than the current node data then go left 
	if (*data < *root->data) {
		//if left child is nullptr then insert
		if (root->leftChild == nullptr) {
			Node* newNode = new Node;
			newNode->data = data;
			root->leftChild = newNode;
			root->leftChild->count++;
			this->numberOfNodes++;
			return true;
		}
		//if left child is not nullptr, then go to next left child
		return insertHelper(root->leftChild, data);
	}
	//if data is greater than current root data then go left 
	if (*data > *root->data) {
		//if right child is nullptr then insert there 
		if (root->rightChild == nullptr) {
			Node* newNode = new Node;
			newNode->data = data;
			root->rightChild = newNode;
			root->rightChild->count++;
			this->numberOfNodes++;
			return true;
		}
		//if right child is not nullptr, then go to next right child
		return insertHelper(root->rightChild, data);
	}
	return false;
}

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
bool SearchTree::remove(const Comparable& data) {
	return deleteNode(root_, data);
}

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
bool SearchTree::deleteNode(Node*& root, const Comparable& data)
{
	if (root == nullptr)
		return false;
	//if data is same as data at node then decrement count
	else if (data == *root->data) {
		root->count--;
		//if count is 0, then remove node 
		if (root->count == 0) {
			deleteRoot(root);
			this->numberOfNodes--;
		}
		return true;
	}
	//if data is less than, go left
	else if (data < *root->data)
		return deleteNode(root->leftChild, data);
	//if data is greater than go right 
	else
		return deleteNode(root->rightChild, data);
}

/**
 * deleteRoot
 * this is a recursive function deletes the root if the node has either
 * no children or one child. if the node has two children, the function calls
 * findAndDeleteMostLeft() in order to keep the order of the BST
 * Preconditions: root can not be nullptr
 * Postconditios: deletes the node and retains BST order
 * @param root: pointer to root of SearchTree
 */
void SearchTree::deleteRoot(Node*& root)
{
	delete root->data;
	root->data = nullptr;

	//if both children are nullptr just delete root
	if (root->leftChild == nullptr && root->rightChild == nullptr) {
		delete root;
		root = nullptr;
	}
	//if one of the children is nullptr, have root point to non nullptr child 
	else if (root->leftChild == nullptr || root->rightChild == nullptr) {
		Node* tmp = root;
		root = root->leftChild == nullptr ? root->rightChild : root->leftChild;
		delete tmp;
		tmp = nullptr;
	}
	//if node has two children 
	else {
		root->data = findAndDeleteMostLeft(root->rightChild);
	}
}

/**
 * findAndDeleteMostLeft
 * this is a recursive function that finds the greatest value node
 * in the left subtree and deletes it
 * Preconditions: root can not be nullptr
 * Postconditios: returns the data that will replace the deleted node
 * @param root: pointer to root of SearchTree
 * @return: data of node that will replace the deleted nodes place
 */
Comparable* SearchTree::findAndDeleteMostLeft(Node*& root)
{
	//if leftChild is nullptr, save data from node
	if (root->leftChild == nullptr) {
		Comparable* data = root->data;
		Node* junk = root;
		root = root->rightChild;
		delete junk;
		junk = nullptr;
		return data;
	}
	else
		return findAndDeleteMostLeft(root->leftChild);
}

/**
 * retrieve
 * this function calls retrieveHelper in order to return the data that is
 * entered in the function
 * Preconditions: none
 * Postconditios: returns the data if found and if not returns nullptr
 * @param data: pointer to a Comparable object
 * @return: returns the data if found and if not returns nullptr
 */
const Comparable* SearchTree::retrieve(const Comparable& data) const {
	return retrieveHelper(root_, data);
}

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
const Comparable* SearchTree::retrieveHelper(const Node* root, const Comparable& data) const
{
	if (root == nullptr)
		return nullptr;
	else if (data == *root->data)
		return root->data;
	else if (data < *root->data)
		return retrieveHelper(root->leftChild, data);
	else
		return retrieveHelper(root->rightChild, data);
}

/**
 * makeEmpty
 * this function calls makeEmptyHelper and deletes all nodes in
 * SearchTree
 * Preconditions: none
 * Postconditios: empty SearchTree
 * @param root: pointer to root of SearchTree
 */
void SearchTree::makeEmpty() {
	makeEmptyHelper(this->root_);
}

/**
 * makeEmptyHelper
 * this recursive function deletes all nodes in
 * SearchTree
 * Preconditions: none
 * Postconditios: empty SearchTree
 * @param root: pointer to root of SearchTree
 * @param data: pointer to a Comparable object
 */
void SearchTree::makeEmptyHelper(Node*& root) {
	if (root != nullptr) {
		makeEmptyHelper(root->leftChild);
		makeEmptyHelper(root->rightChild);
		delete root->data;
		root->data = nullptr; //set data to nullptr
		delete root;
		root = nullptr;
	}
}

/**
* print 
* prints the tree in order
* Precondtions: none 
* Postconidtions: prints the tree's contents
*/
void SearchTree::print() const {
	inorderPrint(root_);
}


/**
* inorderPrint
* this function takes in root of SearchTree and recursively prints the
* data and count in inorder
* Preconditions: none
* Postconditions: the SearchTree is printed in inorder
* @param root: pointer to root of SearchTree
*/
void SearchTree::inorderPrint(Node* root) const {
	if (root != nullptr) {
		inorderPrint(root->leftChild);
		root->data->print();

		//cout << *root->data << " " << root->count << endl;
		inorderPrint(root->rightChild);
	}
}


/**
* createVector
* this function calls the createVector function 
* which takes in a root of SearchTree and stores
* all elements in the tree in a vector and returns the vector
* Preconditions: none
* Postconditions: return a vector of Comparables
*/
vector<Comparable*> SearchTree::traverseInOrder() const{
	return createVector(root_);

}

/**
* createVector
* this function takes in a root of SearchTree and stores
* all elements in the tree in a vector and returns the vector
* Preconditions: none
* Postconditions: return a vector of Comparables
*/
vector<Comparable*> SearchTree::createVector(Node* root) const {
	vector<Comparable*> items;
	if (root != nullptr) {
		createVector(root->leftChild);
		//hopefully can do this
		items.push_back(root->data);
		createVector(root->rightChild);
	}
	return items;
}