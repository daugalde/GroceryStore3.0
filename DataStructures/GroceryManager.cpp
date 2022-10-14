#include <iostream>
#include "GroceryManager.h"
#include "Client.h"

using namespace std;

void GroceryManager::InitStoreLoad()
{
	FileLoader loader;

	this->setStore(loader.LoadFiles());
}

Client* GroceryManager::GetValidRegisteredClient(string clientId)
{

	Object* obj = this->getStore().getClients().GetObjectById(stoi(clientId));

	if (obj)
	{
		Client* c = static_cast<Client*>(obj);

		cout << "El Cliente : " << c->getName() << " es Valido para realizar compras." << endl;

		cout << "\nPresione una tecla para continuar." << endl;

		return c;
	}

	cout << "El Cliente no es valido para comprar en la tienda" << endl;

	return NULL;
}

void GroceryManager::QueueClient(Client* c)
{

	this->getClientsQueue()->Push(c);

}

void GroceryManager::BillClient()
{
	Client* client = static_cast<Client*>(clientsQueue->Pop());

	Store currentStore = getStore();

	List currentInventory = currentStore.getInventory();

	float totalPrice = 0.00;

	if (client != NULL && client->getGroceryItems()->Length() != 0)
	{
		totalPrice = client->getGroceryItems()->Sum(currentInventory);

		client->getGroceryItems()->Display("Item");

		currentStore.setSales(client->getGroceryItems()->Join(currentStore.getSales()));

		client->setTotalInvoiced(client->getTotalInvoiced() + totalPrice);

		client->setInvoices(client->getInvoices() + 1);

		getProcessedClients()->Push(client);

		cout << "\nTotal a Pagar : " << totalPrice << " Colones. " << endl;

		cout << "\nPresione una tecla para volver al menu anterior." << endl;
	}
	else {
		cout << "No Hay Clientes en Cola \nPresione una tecla para volver al menu anterior." << endl;
	}
}

void GroceryManager::CheckIfShelfShouldBeLoaded() {
	
	Store currentStore = getStore();

	List* currentSales = currentStore.getSales();

	BinarySearchTree* currentAisles = currentStore.getAisles();

	List* currentHotItems = currentStore.getHotItems();

	if (currentSales != NULL)
	{
		//currentSales->GetItemsToRefillShelf(currentStore.getInventory(), currentAisles, currentHotItems);
		cout << "\nProductos en Gondolas han sido rellenados" << endl;
	}
	cout << "\nPresione una tecla para volver al menu anterior." << endl;
}

void GroceryManager::CheckIfInvetoryShouldBeLoaded()
{
	Store currentStore = getStore();

	List* currentSales = currentStore.getSales();

	BinarySearchTree* currentAisles = currentStore.getAisles();

	if (currentSales != NULL)
	{
		//currentSales->GetItemsToRefillInventory(currentStore.getInventory(), currentAisles );
		cout << "\nProductos en Inventario han sido rellenados" << endl;
	}
	else {
		cout << "No Es Necesario Rellenar Inventatio\nPresione una tecla para volver al menu anterior." << endl;
	}
};

void GroceryManager::ShowReports()
{
	string confirm = "";

	string id = "";

	string aisleId = "";

	Menu::DisplayReportMenu();
	Store currentStore;
	do
	{

		getline(cin, confirm);

		if (confirm.length() == 0) {

			Menu::DisplayReportMenu();
			confirm = " ";
			continue;
		}

		switch (stoi(confirm))
		{
		case 1:
			Menu::ClearMenu();
			currentStore = getStore();
			//currentStore.getAisles()->DisplayMostVisitedAisle();
			break;
		case 2:
			Menu::ClearMenu();
			currentStore = getStore();
			//currentStore.getAisles()->DisplayLessVisitedAisle();
			break;
		case 3:
			Menu::ClearMenu();
			cout << "Modulo No Implementado Presione Enter para volver al menu anterior\n";
			break;
		case 4:
			Menu::ClearMenu();
			cout << "Modulo No Implementado Presione Enter para volver al menu anterior\n";
			break;
		case 5:
			Menu::ClearMenu();
			cout << "Cliente Con Mas Compras\n";
			currentStore = getStore();
			currentStore.getClients().DisplayClientWithMostInvoices();
			break;
		case 6:
			Menu::ClearMenu();
			cout << "Cliente Con Menos Compras\n";
			currentStore = getStore();
			currentStore.getClients().DisplayClientWithLessInvoices();
			break;
		case 7:
			Menu::ClearMenu();
			cout << "Productos Mas Cargados en godola\n";
			currentStore = getStore();
			if (currentStore.getHotItems()->Length() > 0)
			{
				currentStore.getHotItems()->Display("sales");
			}
			else {
				cout << "No hay Items Cargados en gondola\n";
				cout << "Presione enter para continuar\n";
			}
			break;
		case 8:
			Menu::ClearMenu();
			cout << "Cliente Con Mayor Cantidad de Facturas\n";
			getProcessedClients()->DisplayClientWithGreatestInvoiceCount();
			break;
		case 9:
			Menu::ClearMenu();
			cout << "Marcas de todos los productos de marca vendidos\n";
			currentStore = getStore();
			if (currentStore.getSales()->Length() > 0)
			{
				currentStore.getSales()->Display("Sales");
			}
			else {
				cout << "No hay marcas\n";
				cout << "Presione enter para continuar\n";
			}
			break;
		case 10:
			Menu::ClearMenu();
			cout << "El monto mayor de una factura en la Tienda\n";
			currentStore = getStore();
			currentStore.getClients().DisplayGreatestInvoicedAmount();
			break;
		case 11:
			Menu::ClearMenu();
			cout << "Todos los productos de un pasillo de la Tienda\n";
			cout << "Por favor indicar el id del pasillo\n";
			currentStore = getStore();
			//currentStore.getAisles()->Display("aisle");
			getline(cin, aisleId);
			if (Menu::Is_number(aisleId))
			{
				Menu::ClearMenu();
				currentStore = getStore();
				//currentStore.getAisles()->DisplayAllProductsByAisleId(stoi(aisleId));
				cout << "Presione enter para continuar\n";
			}
			else {
				cout << "Opcion Invalida, Presione enter para continuar\n";
			}
			break;
		case 12:
			Menu::ClearMenu();
			cout << "Clientes de la Tienda\n";
			currentStore = getStore();
			currentStore.getClients().Display("client");
			break;
		case 13:
			Menu::ClearMenu();
			cout << "Pasillos de la Tienda\n";
			currentStore = getStore();
			//currentStore.getAisles()->Display("aisle");
			break;
		case 14:
			Menu::ClearMenu();
			cout << "Inventario de la Tienda\n";
			currentStore = getStore();
			currentStore.getInventory().Display("inventory");
			break;
		case 15:
			cout << "Desea Salir ? Presione Enter o Cualquier Tecla para volver al menu\n";
			getline(cin, confirm);
			if (confirm == "")
			{
				return;
			}
			else {
				Menu::DisplayReportMenu();
				confirm = " ";
			}
			break;
		default:
			Menu::DisplayReportMenu();
			break;
		}

	} while (confirm.length() != 0);
}