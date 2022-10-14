#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// **************************
// *	ESTRUCTURA GRAFO	*
// **************************

// N. Director
//	[A] -> [a] > [a] > [a] > [a]	<--N. Adyacencia
//	 |
//	[B] -> [b] > [b] > [b]
//	 |
//	[C]
//	 |
//	[D]

//Clase Nodo Director
class NodoVertice {
private:
	friend class NodoAdyacencia;

public:
	int codigoCiudad;
	string nombreCiudad;
	bool visitado;
	bool procesado;

	NodoVertice* sigVertice;
	NodoAdyacencia* listaAdyacencia;

	NodoVertice(int codigoCiudad, string nombreCiudad) {
		this->codigoCiudad = codigoCiudad;
		this->nombreCiudad = nombreCiudad;
		sigVertice = NULL;
		listaAdyacencia = NULL;
		visitado = procesado = false;
	}
};

//Clase Nodo Adyacencia
class NodoAdyacencia {
public:
	int factorPeso;

	NodoVertice* raizDirector;
	NodoAdyacencia* siguienteAdy;

	NodoAdyacencia(NodoVertice* verticeDestino) {
		raizDirector = verticeDestino;
		siguienteAdy = NULL;
		factorPeso = 0;
	}
};

//Clase Grafo
class estructuraGrafo {
private:
	void actualizarVisitadoProcesado();
	int cantidadVertices();
	bool existeCiclo(NodoVertice* verticeOrigen, NodoVertice* verticeDestino);

public:
	NodoVertice* GrafoPrimero;

	estructuraGrafo() : GrafoPrimero(NULL) {};
	~estructuraGrafo();

	void insertarVertice(int codigoCiudad, string nombre);
	void insertarArista(int vertice_Origen, int vertice_Destino, int factor);
	void algoritmo_Prim();
	void algoritmo_Kruskal();
	void algoritmo_Dijkstra(int Origen, int Destino);
	void algoritmo_Articulacion();
	NodoVertice* buscarVertice(int verticeBuscado);
};

// **********************
// *	LISTA SIMPLE	*
// **********************

class nodoLista_Grafo {
public:
	NodoVertice* valor;
	int factor;

	nodoLista_Grafo* siguiente;

	nodoLista_Grafo(NodoVertice* valor) {
		this->valor = valor;
		factor = 0;
		this->siguiente = NULL;
	}
	nodoLista_Grafo(int factor) {
		this->factor = factor;
		this->valor = NULL;
		this->siguiente = NULL;
	}
};
class listaSimple_Grafo {

public:
	nodoLista_Grafo* primero;

	listaSimple_Grafo() : primero(NULL) {};
	~listaSimple_Grafo();

	bool listaVacia() { return primero == NULL; };
	void insertarInicio(NodoVertice* valor);
	void insertarFinal(int valor);
	void insertarFinal(NodoVertice* valor);
	void borrarPosicion(int posicion);
	void borrarInicio();
	void borrarFinal();
	nodoLista_Grafo* obtenerFinal();
};

// **************************************
// *	PILA SIMPLE	(Ptos Articulacion)	*
// **************************************

class nodoPila {
public:
	NodoVertice* valor;
	nodoPila* siguiente;

	nodoPila(NodoVertice* valor) {
		this->valor = valor;
		siguiente = NULL;
	}

	friend class pilaSimple_Grafo;
};

class pilaSimple_Grafo {
public:
	nodoPila* tope;

	pilaSimple_Grafo() : tope(NULL) {};

	bool pilaVacia() { return tope == NULL; };
	void push(NodoVertice* valor);
	nodoPila* pop();
};

// **********************
// *	Clase de arbol	*
// **********************

// ******************************************
// *	Lista de nodos => Ramas de n-ario	*
// ******************************************

class nodoLista_arbolGrafo {
public:
	friend class Lista_arbolGrafo;
	friend class nodoArbolGrafo;

	nodoArbolGrafo* nodo;
	nodoLista_arbolGrafo* siguiente;

	nodoLista_arbolGrafo(nodoArbolGrafo* nodo) {
		this->nodo = nodo;
		siguiente = NULL;
	}
};

class Lista_arbolGrafo {
public:
	nodoLista_arbolGrafo* primero;

	Lista_arbolGrafo() : primero(NULL) {};
	~Lista_arbolGrafo();

	void insertarNodo(nodoArbolGrafo* valor);
	void borrarFinal();
	bool listaVacia() { return primero == NULL; };
};

class nodoArbolGrafo {

public:
	NodoVertice* valor;
	Lista_arbolGrafo ramas;
	Lista_arbolGrafo aristaRetroceso;
	int Num;
	int Bajo;

	nodoArbolGrafo(NodoVertice* valor) : valor(valor), Num(0), Bajo(0) {};
};

class arbol_Grafo {

private:
	void insertar(NodoVertice* valorNuevo, NodoVertice* valorPadre, nodoArbolGrafo* raizActual, bool* insertado);
	void eliminarArbol(nodoArbolGrafo* raiz);

public:
	nodoArbolGrafo* raiz;

	arbol_Grafo() : raiz(NULL) {};
	~arbol_Grafo() { eliminarArbol(raiz); delete raiz; raiz = NULL; };

	void insertarRama(NodoVertice* valorNuevo, NodoVertice* valorPadre);
	void generarAristasRetroceso(nodoArbolGrafo* raizActual, Lista_arbolGrafo* nodosRetroceso, nodoArbolGrafo* nodoPadre);
	void inicializarNum(nodoArbolGrafo* raizActual, int* num);
	void inicializarBajo(nodoArbolGrafo* raizActual, Lista_arbolGrafo* listaRetroceso, nodoArbolGrafo* nodoPadre);
	void compararBajoNum(nodoArbolGrafo* raizActual, nodoArbolGrafo* nodoPadre, Lista_arbolGrafo* listaArticulacion);
	void datosNumBajoStr(nodoArbolGrafo* raizActual, string* linea, nodoArbolGrafo* nodoPadre);
};
