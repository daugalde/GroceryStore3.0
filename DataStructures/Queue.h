#include "Node.h"

using namespace std;

class Queue {

private:
	PointerNode front;
	PointerNode back;

public:

	Queue() {
		front = NULL;
		back = NULL;
	}

	bool IsEmpty() { return front == NULL && back == NULL; }

	void Push(Object* obj); // Inserts lef to right

	Object* Pop(); // Extract from right FIFO

	void Display(); // Print Queue Values

	int Length();
};
