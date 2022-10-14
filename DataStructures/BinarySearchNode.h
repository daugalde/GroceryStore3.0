#pragma once
#include "Object.h"
using namespace std;

class BinarySearchNode {
private:
	Object* value;
	BinarySearchNode* left;
	BinarySearchNode* right;
public:

	BinarySearchNode(Object* value) {
		left = right = NULL;
		this->value = value;
	}

	void setLeft(BinarySearchNode*);

	BinarySearchNode*& getLeft();

	void setRight(BinarySearchNode*);

	BinarySearchNode*& getRight();

	friend class Object;
	friend class BinarySearchTree;
};