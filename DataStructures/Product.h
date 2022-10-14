#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Product : public Object {

private:

	int productId;
	int makeId;
	int shelfQuantity;
	float price;

public:

	Product() {
		productId = 0;
		makeId = 0;
		shelfQuantity = 0;
		price = 0.0;
	}

	Product(int id, string name, int make) : Object(id, name) {
		this->makeId = make;
	}

	int getMakeId() {
		return this->makeId;
	};

	void setMakeId(int make) {
		this->makeId = make;
	};

	int getProductId() {
		return this->productId;
	};

	void setProductId(int productId) {
		this->productId = productId;
	};

	int getShelfQuantity() {
		return this->shelfQuantity;
	};

	void setShelfQuantity(int shelfQuantity) {
		this->shelfQuantity = shelfQuantity;
	};

	float getPrice() {
		return this->price;
	};

	void setPrice(float price) {
		this->price = price;
	};

	friend class List;
};
