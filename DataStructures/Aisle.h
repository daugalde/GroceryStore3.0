#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Aisle : public Object {
private:

	string type;
	List* productAisles;

public:

	Aisle() {
		productAisles = NULL;
	}

	Aisle(int id, string name, string type) : Object(id, name) {
		this->type = type;
	}

	List* getProductAisles() {
		return productAisles;
	};

	void setProductAisles(List* productAisles) {
		this->productAisles = productAisles;
	};

	friend class List;
};
