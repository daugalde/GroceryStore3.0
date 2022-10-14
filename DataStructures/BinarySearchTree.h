#pragma once
#include "BinarySearchNode.h"
class BinarySearchTree {

private:
	BinarySearchNode* root;

	// Private Methods
	void addNode(Object* value, BinarySearchNode* root);
	string displayNodeObjectInfo(BinarySearchNode*& root);

public:
	// Constructors
	BinarySearchTree() : root(NULL) {};

	BinarySearchTree(Object* obj);

	// Gets and Sets
	BinarySearchNode* getRoot();

	void setRoot(BinarySearchNode* root);

	//Methods
	void add(Object* value);

	string getInfo();
};