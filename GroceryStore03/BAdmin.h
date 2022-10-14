#pragma once
#pragma once
#include <iostream>
using namespace std;

// ******************************
// * ARBOL B DE ADMINISTRADORES *
// ******************************


class informacionAdministrador {
public:
	int CodAdministrador;
	string nombre;
	informacionAdministrador(int CodAdministrador, string nombre) {
		this->CodAdministrador = CodAdministrador;
		this->nombre = nombre;
	}
};

class nodoBinario_Admin {
public:
	informacionAdministrador* claves[4] = { 0 };
	nodoBinario_Admin* ramas[5] = { 0 };
	int cuentas = 0;

	nodoBinario_Admin() {}

	friend class arbolbinario_b_Admin;
};

class arbolbinario_b_Admin {

private:
	void buscarNodo(int claveNueva, nodoBinario_Admin** P, bool* encontrado, int* K);
	void empujar(int CodAdministrador, string nombre, nodoBinario_Admin** R, bool* empujarArriba, informacionAdministrador** Mdna, nodoBinario_Admin** X);
	void meterHoja(informacionAdministrador** X, nodoBinario_Admin** Xder, nodoBinario_Admin** P, int* K);
	void dividirNodo(informacionAdministrador* X, nodoBinario_Admin* Xder, nodoBinario_Admin** P, int* K, informacionAdministrador** Mda, nodoBinario_Admin** Mder);
	void destruirArbol(nodoBinario_Admin* raiz);
	void insertar(int CodAdministrador, string nombre, nodoBinario_Admin** raiz);


public:
	nodoBinario_Admin* raiz;

	arbolbinario_b_Admin() : raiz(NULL) {};
	~arbolbinario_b_Admin();

	void insertarNodo(int CodAdministrador, string nombre);
	informacionAdministrador* buscarAdmins(nodoBinario_Admin** raiz, int contrasena);
};
// **********************************
// *	COMUNICADOR DE ESTRUCTURA	*
// **********************************

class estructuraADMIN {
public:
	arbolbinario_b_Admin arbolAdministradores;
};
