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

class nodoArbolBinario_B {
public:
	informacionAdministrador* claves[4] = { 0 };
	nodoArbolBinario_B* ramas[5] = { 0 };
	int cuentas = 0;

	nodoArbolBinario_B() {}

	friend class arbolbinario_b;
};

class arbolbinario_b {

private:
	void buscarNodo(int claveNueva, nodoArbolBinario_B** P, bool* encontrado, int* K);
	void empujar(int CodAdministrador, string nombre, nodoArbolBinario_B** R, bool* empujarArriba, informacionAdministrador** Mdna, nodoArbolBinario_B** X);
	void meterHoja(informacionAdministrador** X, nodoArbolBinario_B** Xder, nodoArbolBinario_B** P, int* K);
	void dividirNodo(informacionAdministrador* X, nodoArbolBinario_B* Xder, nodoArbolBinario_B** P, int* K, informacionAdministrador** Mda, nodoArbolBinario_B** Mder);
	void destruirArbol(nodoArbolBinario_B* raiz);
	void insertar(int CodAdministrador, string nombre, nodoArbolBinario_B** raiz);
	// BORRADO
	void Eliminar(int contrasena, nodoArbolBinario_B** raiz);
	void EliminarRegistro(int contrasena, nodoArbolBinario_B** raiz, bool* Encontrado);
	void Quitar(nodoArbolBinario_B** P, int* K);
	void Sucesor(nodoArbolBinario_B** P, int* K);
	void Restablecer(nodoArbolBinario_B** P, int* K);
	void MoverDerecha(nodoArbolBinario_B** P, int* K);
	void MoverIzquierda(nodoArbolBinario_B** P, int K);
	void Combina(nodoArbolBinario_B** P, int K);

public:
	nodoArbolBinario_B* raiz;

	arbolbinario_b() : raiz(NULL) {};
	~arbolbinario_b();

	void insertarNodo(int CodAdministrador, string nombre);
	informacionAdministrador* buscarAdmins(nodoArbolBinario_B** raiz, int contrasena);


	//BORRADO
	void borrarNodo(int contrasena);
};
// **********************************
// *	COMUNICADOR DE ESTRUCTURA	*
// **********************************

class estructuraADMIN {
public:
	arbolbinario_b arbolAdministradores;
};
