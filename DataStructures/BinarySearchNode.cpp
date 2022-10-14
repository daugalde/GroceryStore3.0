#pragma once
#include <iostream>
#include <string>
#include "Object.h"
#include "BinarySearchNode.h"

using namespace std;

void BinarySearchNode::setLeft(BinarySearchNode* left) {
	this->left = left;
}

BinarySearchNode*& BinarySearchNode::getLeft() {
	return left;
}

void BinarySearchNode::setRight(BinarySearchNode* right) {
	this->right = right;
}

BinarySearchNode*& BinarySearchNode::getRight() {
	return right;
}
