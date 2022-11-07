#pragma once
#include <iostream>
using namespace std;

// ******************************
// * ARBOL B DE VENDEDL *
// ******************************


class informacionVendedor {
public:
	int CodVendedor;
	string nombre;
	informacionVendedor(int CodVendedor, string nombre) {
		this->CodVendedor = CodVendedor;
		this->nombre = nombre;
	}
};

class nodoBinario_Vendedor {
public:
	informacionVendedor* claves[4] = { 0 };
	nodoBinario_Vendedor* ramas[5] = { 0 };
	int cuentas = 0;

	nodoBinario_Vendedor() {}

	friend class arbolbinario_b_Vendedor;
};

class arbolbinario_b_Vendedor {

private:
	void buscarNodo(int claveNueva, nodoBinario_Vendedor** P, bool* encontrado, int* K);
	void empujar(int CodVendedor, string nombre, nodoBinario_Vendedor** R, bool* empujarArriba, informacionVendedor** Mdna, nodoBinario_Vendedor** X);
	void meterHoja(informacionVendedor** X, nodoBinario_Vendedor** Xder, nodoBinario_Vendedor** P, int* K);
	void dividirNodo(informacionVendedor* X, nodoBinario_Vendedor* Xder, nodoBinario_Vendedor** P, int* K, informacionVendedor** Mda, nodoBinario_Vendedor** Mder);
	void destruirArbol(nodoBinario_Vendedor* raiz);
	void insertar(int CodVendedor, string nombre, nodoBinario_Vendedor** raiz);


public:
	nodoBinario_Vendedor* raiz;

	arbolbinario_b_Vendedor() : raiz(NULL) {};
	~arbolbinario_b_Vendedor();
	informacionVendedor* buscarVen(nodoBinario_Vendedor** raiz, int CodVendedor);

	void insertarNodo(int CodVendedor, string nombre);
};
// **********************************
// *	COMUNICADOR DE ESTRUCTURA	*
// **********************************

class estructuraVendedor {
public:
	arbolbinario_b_Vendedor arbolVendedor;
};
