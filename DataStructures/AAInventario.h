#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

// ***************************************************
// *	       ARBOL DOBLE AA DE INVENTARIOS         *
// ***************************************************

class nodoBinario_AA_Inventario {

private :

	Object* value;
	int nivel;

public:

	nodoBinario_AA_Inventario* izq;
	nodoBinario_AA_Inventario* der;

	nodoBinario_AA_Inventario(Object* obj ) {
		//this->CodigoPasillo = CodigoPasillo;
		//this->CodigoProducto = CodigoProducto;
		//this->CodigoMarca = CodigoMarca;
		//this->nombre = nombre;
		//this->CantStock = CantStock;
		//this->CodCan = CodCan;
		//this->setId(CodigoProducto);
		this->value = obj;
		izq = der = NULL;
		nivel = 0;
	}

	Object* getValue() {
		return this->value;
	};

	void setValue(Object* value) {
		this->value = value;
	};

	int getNivel() {
		return this->nivel;
	};

	void setNivel(int nivel) {
		this->nivel = nivel;
	};

	friend class arbolBinario_AA_Inventario;
};

class arbolBinario_AA_Inventario {
private:
	void eliminarArbolInner(nodoBinario_AA_Inventario** raiz);
	//void insertarDerecho(nodoBinario_AA_Inventario** raiz, int Id, int IdProducto, int IdMarca, string nombre, int CantStock, int CodCan, int nivel);
	void insertarDerecho(nodoBinario_AA_Inventario** raiz, Object* obj, int nivel);
	void reparto(nodoBinario_AA_Inventario** raiz);
	void giro(nodoBinario_AA_Inventario** raiz);
	void InsertarNodoAA(nodoBinario_AA_Inventario** raiz, Object* obj, int nivel);
	void borrarAA(nodoBinario_AA_Inventario** raiz, Object* obj);
	void antecesorBorrado(nodoBinario_AA_Inventario** nodoIzq, nodoBinario_AA_Inventario** raiz);
	void decrementarNivel(nodoBinario_AA_Inventario* raiz);

public:
	nodoBinario_AA_Inventario* raiz;

	arbolBinario_AA_Inventario();
	~arbolBinario_AA_Inventario();
	void borrarNodo(int codigoMarca);


	void eliminarArbol(nodoBinario_AA_Inventario** raiz);
	void actuializarStock(nodoBinario_AA_Inventario* raiz, Object* obj);
	void InsertarNodo(Object* obj);
	nodoBinario_AA_Inventario* buscarInv(nodoBinario_AA_Inventario* raiz, Object* obj);
};
// **********************************
// *	COMUNICADOR DE ESTRUCTURA	*
// **********************************

class estructuraInventario {
public:
	arbolBinario_AA_Inventario arbolPrincipal_Inventario;
};