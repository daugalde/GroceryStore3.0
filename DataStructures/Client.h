#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "Aisle.h"
#include "ProductAisle.h"
#include "Product.h"
#include "Item.h"

using namespace std;

class Client : public Object {

private:
	int id = 0;
	string name = "";
	string phone = "";
	string mail = "";
	List* groceryItems;
	int invoices = 0;
	float totalInvoiced = 0.0;

public:  // Constructors

	Client() {}

	Client(int clientId, string clientName , string clientPhone, string clientMail )
	{
		id = clientId;
		name = clientName;
		phone = clientPhone;
		mail = clientMail;
	}

	string getPhone() {
		return this->phone;
	};

	void setPhone(string phone) {
		this->phone = phone;
	};

	string getEmail() {
		return this->mail;
	};

	void setEmail(string mail) {
		this->mail = mail;
	};

	List* getGroceryItems() {
		return this->groceryItems;
	}

	void setGroceryItems(List* groceryItems) {
		this->groceryItems = groceryItems;
	}

	int getInvoices() {
		return this->invoices;
	}

	void setInvoices(int invoices) {
		this->invoices = invoices;
	}

	int getTotalInvoiced() {
		return this->totalInvoiced;
	}

	void setTotalInvoiced(float totalInvoiced) {
		this->totalInvoiced = totalInvoiced;
	}

	void BuyProducts(List* groceryItems) {

		string selectedAsileId;

		string selectedProductId;

		string selectedProductMakeId;

		string selectedProductQuantity;

		do
		{
			getline(cin, selectedAsileId);

			if (selectedAsileId == "")
			{
				selectedAsileId = " ";
			}

			if (Menu::Is_number(selectedAsileId) && groceryItems->HasAisleId(stoi(selectedAsileId)))
			{
				cout << flush;

				system("CLS");

				Aisle* aisle = static_cast<Aisle*>(groceryItems->GetObjectById(stoi(selectedAsileId)));

				aisle->setVisits(aisle->getVisits() + 1);

				do {
					if (aisle != NULL)
					{
						cout << flush;

						system("CLS");

						cout << "\nPor favor seleccione el Tipo de producto a comprar\n";

						aisle->getProductAisles()->Display("productAisle");

						getline(cin, selectedProductId);

						if (Menu::Is_number(selectedProductId))
						{
							ProductAisle* productsAisle = static_cast<ProductAisle*>(aisle->getProductAisles()->GetObjectByProductId(stoi(selectedProductId)));

							productsAisle->setVisits(productsAisle->getVisits() + 1);

							do {
								if (productsAisle != NULL)
								{
									cout << flush;

									system("CLS");

									cout << "\nPor favor seleccione el producto a comprar\n";

									productsAisle->getProducts()->Display("product");

									getline(cin, selectedProductMakeId);

									if (Menu::Is_number(selectedProductMakeId))
									{
										Product* product = static_cast<Product*>(productsAisle->getProducts()->GetObjectByMakeProductId(stoi(selectedProductMakeId)));

										if (product != NULL)
										{
											product->setVisits(product->getVisits() + 1);

											cout << "\nPor favor seleccione la Cantidad existe " << product->getShelfQuantity() << " unidades\n";

											getline(cin, selectedProductQuantity);

											if (Menu::Is_number(selectedProductQuantity) && stoi(selectedProductQuantity) <= product->getShelfQuantity())
											{
												Item* item = (new Item(product->getId(), product->getName(), product->getMakeId(), product->getPrice(), stoi(selectedProductQuantity)));

												List* list = new List();

												list->Push(item);

												setGroceryItems(list);
												this->setVisits(this->getVisits() + 1);
												product->setShelfQuantity(product->getShelfQuantity() - stoi(selectedProductQuantity));
												selectedAsileId = "";
												selectedProductId = "";
											}
											else {
												cout << "\nCantidad invalida" << endl;
											}
										}

									}
									else {
										cout << "\nProducto invalido" << endl;
									}
								}
								else {
									cout << "\nTipo de Producto No encontrado";
									selectedProductId = " ";
								}
							} while (selectedProductId.length() != 0);
						}
						else {
							cout << "\nProducto No encontrado";
						}
					}
					else {
						cout << "\nPasillo No encontrado";
					}
				} while (selectedAsileId.length() != 0);
			}
			else {

				cout << flush;

				system("CLS");

				cout << "\nPor Favor Seleccionar un Pasillo o cualquier tecla para volver al menu anterior " << endl;

				groceryItems->Display("aisle");
			}

			if (selectedAsileId == "")
			{
				cout << "\nLos productos Fueron Agregados a su Canasta." << endl;
				cout << "\nPresione una tecla para continuar." << endl;
			}
		} while (selectedAsileId.length() != 0);

	}

	friend class List;
	//friend class FileLoader;
};