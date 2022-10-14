#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Aisle.h"
#include "ProductAisle.h"
#include "List.h"
#include "Store.h"

using namespace std;

class FileLoader {

private:


public:
	FileLoader() { }

	~FileLoader();

	Store LoadFiles();

	BinarySearchTree* ReadAndLoadAilesFile();

	void ReadAndLoadProductAileFile(Aisle* aisle);

	void ReadAndLoadProductsFile(ProductAisle* productAisle);

	List ReadAndLoadInvetoryFile();

	List ReadAndLoadClientFile();
};
