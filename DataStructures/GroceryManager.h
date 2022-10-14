#pragma once
#include <iostream>
#include <string>
#include "FileLoader.h"
#include "Client.h"
#include "Queue.h"
#include "Store.h"
using namespace std;

class GroceryManager {

private:
	Store store;
	Queue* clientsQueue;
	List* processedClients;

public:  // Constructors

	GroceryManager() {
		clientsQueue = new Queue();
		processedClients = new List();
	}

	Store getStore() {
		return store;
	}

	void setStore(Store store) {
		this->store = store;
	}

	void setClientsQueue(Queue* queue) {
		this->clientsQueue = queue;
	}

	Queue* getClientsQueue() {
		return clientsQueue;
	}

	void setProcessedClients(List* list) {
		this->processedClients = list;
	}

	List* getProcessedClients() {
		return processedClients;
	}

	void InitStoreLoad();

	Client* GetValidRegisteredClient(string clientId);

	void QueueClient(Client* c);

	void BillClient();

	void CheckIfShelfShouldBeLoaded();

	void CheckIfInvetoryShouldBeLoaded();

	void ShowReports();

	friend class List;
	friend class Queue;
};