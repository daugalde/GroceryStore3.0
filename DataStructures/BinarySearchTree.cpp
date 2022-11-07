#include <iostream>
#include "BinarySearchTree.h"
#include "Aisle.h"
//#include "Aisle.h"
//#include "Node.h"
//#include "ProductAisle.h"
//#include "Product.h"
//#include "Client.h"
//#include "Inventory.h"
//#include "SoldItem.h"

using namespace std;

// Constructors
BinarySearchTree::BinarySearchTree(Object* obj) {
    this->root = new BinarySearchNode(obj);
}

// Gets and Sets
BinarySearchNode* BinarySearchTree::getRoot() {
    return this->root;
}

void BinarySearchTree::setRoot(BinarySearchNode* root) {
    this->root = root;
}

// Private Methods
void BinarySearchTree::addNode(Object* value, BinarySearchNode* node) {
    if (value->getId() < node->value->getId()) {
        if (node->getLeft() == NULL) {
            node->setLeft(new BinarySearchNode(value));
        }
        else {
            addNode(value, node->getLeft());
        }
    }
    else if (value->getId() > node->value->getId()) {
        if (node->getRight() == NULL) {
            node->setRight(new BinarySearchNode(value));
        }
        else {
            addNode(value, node->getRight());
        }
    }
}

string BinarySearchTree::displayNodeObjectInfo(BinarySearchNode*& node) {
    string info = "";
    if (node != NULL)
    {
        info = info + displayNodeObjectInfo(node->getLeft());
        info = info + to_string(node->value->getId()) + "\t" + node->value->getName() + "\r\n";
        info = info + displayNodeObjectInfo(node->getRight());
    }
    return info;
}

// Methods
void BinarySearchTree::add(Object* value) {
    if (this->root == NULL) {
        setRoot(new BinarySearchNode(value));
    }
    else {
        this->addNode(value,this->root);
    }
}

string BinarySearchTree::getInfo() {
    return  this->displayNodeObjectInfo(this->root);
}