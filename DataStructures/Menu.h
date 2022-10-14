#pragma once

using namespace std;

class Menu {

public:

	Menu() {}

	static void Displaymenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\tMENU \n ";
		cout << "===================================================== \n";
		cout << " 1.Comprar\n";
		cout << " 2.Facturar\n";
		cout << " 3.Revisar Gondolas\n";
		cout << " 4.Verficar Inventario \n";
		cout << " 5.Reportes \n";
		cout << " 6.Salir \n";
	}

	static void DisplayReportMenu()
	{
		ClearMenu();
		cout << " ===================================================== \n";
		cout << " \t\t Reportes de Tienda \n ";
		cout << "===================================================== \n";
		cout << " 1.Pasillo Mas Visitado\n";
		cout << " 2.Pasillo Menos Visitado\n";
		cout << " 3.Porductos Mas Vendidos Por Pasillo\n";
		cout << " 4.Marcas Mas Vendidas \n";
		cout << " 5.Cliente Que Mas Compro \n";
		cout << " 6.Cliente Que Menos Compro \n";
		cout << " 7.Producto Mas Cargado en Gondolas \n";
		cout << " 8.Cliente Que Mas Facturo \n";
		cout << " 9.Mostrar todas las Marcas de Productos \n";
		cout << "10.Mostrar Factura de Mayor Monto \n";
		cout << "11.Mostrar Productos Por Pasillo \n";
		cout << "12.Mostrar Todos Los Clientes Registrados en Tienda \n";
		cout << "13.Mostrar Todos Los Pasillos de Tienda \n";
		cout << "14.Mostrar Inventario de Tienda \n";
		cout << "15.Volver al Menu Principal \n";
	}

	static void ClearMenu() {
		cout << flush;
		system("CLS");
	}

	bool static Is_number(const std::string& s)
	{
		return !s.empty() && std::find_if(s.begin(),
			s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
	}
};
