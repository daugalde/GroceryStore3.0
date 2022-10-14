#include <iostream>
#include "Node.h"
#include "Queue.h"
#include "Item.h"
using namespace std;

void Queue::Push(Object* obj) {

	if (front == NULL) { // First element
		front = new Node(obj);
		back = front;
	}
	else { // Rest elements
		back = new Node(obj, back);
	}
};

Object* Queue::Pop() {
	Object* obj;
	if (front == NULL) { // Empty Queue
		obj = NULL;
	}
	else if (back == front) { // Single Element
		obj = front->value;
		back = NULL;
		front = NULL;

	}
	else { // 2 or more elements
		obj = front->value;
		PointerNode aux = back;
		while (aux->NextNode != front) {
			aux = aux->NextNode;
		}
		aux->NextNode = NULL;
		front = aux;

	}
	return obj;
};

void Queue::Display() {

	if (Length() != 0)
	{
		PointerNode aux = back;

		while (aux != NULL) {
			//cout << aux->value << " -> ";
			cout << static_cast<Item*>(aux->value)->getId() << "\t" << aux->value->getName() << "\t" << static_cast<Item*>(aux->value)->getMakeId() << "\t" << static_cast<Item*>(aux->value)->getPrice() << endl;
			aux = aux->NextNode;
		}
	}
	cout << "No Hay Clientes Para Facturar" << endl;
};

int Queue::Length() {
	int cont = 0;

	PointerNode aux = front;
	if (IsEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
	}
};
