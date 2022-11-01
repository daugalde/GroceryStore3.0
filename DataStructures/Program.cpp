#include "MainMenuGrocery.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {

	//GroceryManager manager;

	//manager.InitStoreLoad();

	//Menu::Displaymenu();

	//int yourchoice = 0;

	//string confirm = "";

	//string id = "";

	//Client* currentClient;

	//do
	//{
	//	getline(cin, confirm);

	//	if (confirm.length() == 0) {

	//		Menu::Displaymenu();
	//		confirm = " ";
	//		continue;
	//	}

	//	switch (confirm[0])
	//	{
	//	case '1':
	//		Menu::ClearMenu();

	//		cout << "Porfavor Indicar cedula Cliente : ";

	//		getline(cin, id);

	//		Menu::ClearMenu();
	//		if (Menu::Is_number(id))
	//		{
	//			currentClient = manager.GetValidRegisteredClient(id);

	//			if (currentClient != NULL)
	//			{
	//				//currentClient->BuyProducts(manager.getStore().getAisles());
	//				manager.QueueClient(currentClient);
	//			}
	//		}
	//		else {
	//			cout << "Opcion invalida Por favor Presione cualquier tecla para volver a intentar ";
	//		}
	//		yourchoice = 6;

	//		break;
	//	case '2':
	//		Menu::ClearMenu();
	//		manager.BillClient();
	//		yourchoice = 6;
	//		break;
	//	case '3': 
	//		Menu::ClearMenu();
	//		manager.CheckIfShelfShouldBeLoaded();
	//		yourchoice = 6;
	//		break;
	//	case '4': 
	//		Menu::ClearMenu();
	//		manager.CheckIfInvetoryShouldBeLoaded();
	//		yourchoice = 6;
	//		break;
	//	case '5':
	//		Menu::ClearMenu();
	//		manager.ShowReports();
	//		Menu::Displaymenu();
	//		yourchoice = 6;
	//		break;
	//	case '6':
	//		cout << "Desea Salir ? Presione Y\n";
	//		getline(cin, confirm);
	//		if (confirm == "Y" || confirm == "y")
	//		{
	//			confirm = "";
	//		}
	//		else {
	//			confirm = " ";
	//		}
	//	default:
	//		Menu::Displaymenu();
	//		break;
	//	}

	//} while (confirm.length() != 0) ;

	//return 0;
}
