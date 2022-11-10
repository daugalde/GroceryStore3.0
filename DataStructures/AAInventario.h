#pragma once
#include <iostream>
using namespace std;

// ***************************************************
// *	       ARBOL DOBLE AA DE INVENTARIOS         *
// ***************************************************

class nodoBinario_AA_Inventario {
public:
	int nivel;
	int id;
	int CodigoPasillo;
	int CodigoProducto;
	int CodigoMarca;
	string nombre;
	int CantStock;
	int CodCan;

	nodoBinario_AA_Inventario* izq;
	nodoBinario_AA_Inventario* der;

	nodoBinario_AA_Inventario(int CodigoPasillo, int CodigoProducto, int CodigoMarca, string nombre, int CantStock, int CodCan) {
		this->CodigoPasillo = CodigoPasillo;
		this->CodigoProducto = CodigoProducto;
		this->CodigoMarca = CodigoMarca;
		this->nombre = nombre;
		this->CantStock = CantStock;
		this->CodCan = CodCan;
		this->setId(CodigoProducto);
		izq = der = NULL;
		nivel = 0;
	}

	int getId() {
		return this->id;
	};

	void setId(int id) {
		this->id = id;
	};

	int getCantStock() {
		return this->CantStock;
	};

	void setCantStock(int qty) {
		this->CantStock = qty;
	};

	friend class arbolBinario_AA_Inventario;
};

class arbolBinario_AA_Inventario {
private:
	void eliminarArbol(nodoBinario_AA_Inventario** raiz);
	void insertarDerecho(nodoBinario_AA_Inventario** raiz, int CodigoPasillo, int CodigoProducto, int CodigoMarca, string nombre, int CantStock, int CodCan, int nivel);
	void reparto(nodoBinario_AA_Inventario** raiz);
	void giro(nodoBinario_AA_Inventario** raiz);
	void InsertarNodoAA(nodoBinario_AA_Inventario** raiz, int CodigoPasillo, int CodigoProducto, int CodigoMarca, string nombre, int CantStock, int CodCan, int nivel);
	void borrarAA(nodoBinario_AA_Inventario** raiz, int codigoMarca);
	void antecesorBorrado(nodoBinario_AA_Inventario** nodoIzq, nodoBinario_AA_Inventario** raiz);
	void decrementarNivel(nodoBinario_AA_Inventario* raiz);

public:
	nodoBinario_AA_Inventario* raiz;

	arbolBinario_AA_Inventario();
	~arbolBinario_AA_Inventario();
	void borrarNodo(int codigoMarca);

	void actuializarStock(nodoBinario_AA_Inventario* raiz, int CodigoMarca, int cantidad);
	void InsertarNodo(int CodigoPasillo, int CodigoProducto, int CodigoMarca, string nombre, int CantStock, int CodCan);
	nodoBinario_AA_Inventario* buscarInv(nodoBinario_AA_Inventario* raiz, int codigoMarca);
};
// **********************************
// *	COMUNICADOR DE ESTRUCTURA	*
// **********************************

class estructuraInventario {
public:
	arbolBinario_AA_Inventario arbolPrincipal_Inventario;
};