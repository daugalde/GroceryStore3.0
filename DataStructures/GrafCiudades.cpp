#include "GrafCiudades.h"

// ******************************************
// *	Lista de nodos => Ramas de n-ario	*
// ******************************************

Lista_arbolGrafo::~Lista_arbolGrafo() {
	nodoLista_arbolGrafo* selector;
	while (primero) {
		selector = primero;
		primero = primero->siguiente;
		delete selector;
	}
	primero = NULL;
}
void Lista_arbolGrafo::insertarNodo(nodoArbolGrafo* valor) {
	if (!primero)
		primero = new nodoLista_arbolGrafo(valor);
	else {
		nodoLista_arbolGrafo* aux = primero;
		while (aux->siguiente)
			aux = aux->siguiente;
		aux->siguiente = new nodoLista_arbolGrafo(valor);
	}
}
void Lista_arbolGrafo::borrarFinal() {
	nodoLista_arbolGrafo* selector = primero;
	nodoLista_arbolGrafo* aux = selector;
	while (selector) {
		if (!selector->siguiente)
			break;
		aux = selector;
		selector = selector->siguiente;
	}
	if (aux)
		aux->siguiente = NULL;

	if (selector == primero) {
		delete primero;
		primero = NULL;
	}
	else
		delete selector;
}

// **********************
// *	Clase de arbol	*
// **********************

void arbol_Grafo::eliminarArbol(nodoArbolGrafo* raiz) {
	if (raiz) {
		nodoLista_arbolGrafo* selector = raiz->ramas.primero;

		if (selector)
			eliminarArbol(selector->nodo);

		raiz->ramas.~Lista_arbolGrafo();
	}
}
void arbol_Grafo::insertar(NodoVertice* valorNuevo, NodoVertice* valorPadre, nodoArbolGrafo* raizActual, bool* insertado) {

	if (raizActual->valor->codigoCiudad == valorPadre->codigoCiudad) {
		raizActual->ramas.insertarNodo(new nodoArbolGrafo(valorNuevo));
		*insertado = true;
		return;
	}

	nodoLista_arbolGrafo* selectorNodo = raizActual->ramas.primero;
	while (selectorNodo) {
		insertar(valorNuevo, valorPadre, selectorNodo->nodo, insertado);

		if (*insertado)
			return;

		selectorNodo = selectorNodo->siguiente;
	}
}
void arbol_Grafo::insertarRama(NodoVertice* valorNuevo, NodoVertice* valorPadre) {
	bool temp = false;
	if (!raiz)
		raiz = new nodoArbolGrafo(valorNuevo);
	else
		insertar(valorNuevo, valorPadre, raiz, &temp);
}
void arbol_Grafo::inicializarNum(nodoArbolGrafo* raizActual, int* num) {
	if (raizActual) {
		raizActual->Num = *num;
		*num = *num + 1;

		nodoLista_arbolGrafo* selectorNodo = raizActual->ramas.primero;
		while (selectorNodo) {
			inicializarNum(selectorNodo->nodo, num);
			selectorNodo = selectorNodo->siguiente;
		}
	}
}
void arbol_Grafo::inicializarBajo(nodoArbolGrafo* raizActual, Lista_arbolGrafo* listaPadres, nodoArbolGrafo* nodoPadre) {
	if (raizActual) {
		//No tiene arista retroceso
		if (!raizActual->aristaRetroceso.primero)
			raizActual->Bajo = raizActual->Num;

		//Tiene arista retroceso
		else {
			int nuevoBajo = raizActual->aristaRetroceso.primero->nodo->Num;
			nodoPadre->Bajo = raizActual->Bajo = nuevoBajo;

			nodoLista_arbolGrafo* selectorRetroceso = listaPadres->primero;
			while (selectorRetroceso->nodo != nodoPadre) {
				selectorRetroceso->nodo->Bajo = nuevoBajo;
				selectorRetroceso = selectorRetroceso->siguiente;
			}
		}

		listaPadres->insertarNodo(raizActual);

		nodoLista_arbolGrafo* selectorHoja = raizActual->ramas.primero;
		for (; selectorHoja; selectorHoja = selectorHoja->siguiente)
			inicializarBajo(selectorHoja->nodo, listaPadres, raizActual);

		listaPadres->borrarFinal();

	}
}
void arbol_Grafo::compararBajoNum(nodoArbolGrafo* raizActual, nodoArbolGrafo* nodoPadre, Lista_arbolGrafo* listaArticulacion) {
	if (raizActual) {
		nodoLista_arbolGrafo* selectorHijos = raizActual->ramas.primero;

		//Compara los hijos de la raizPadre -> Bajo(Hijo) >= Num(Padre)
		for (; selectorHijos; selectorHijos = selectorHijos->siguiente)
			if (selectorHijos->nodo->Bajo >= raizActual->Num) {
				listaArticulacion->insertarNodo(raizActual);
				break;
			}

		selectorHijos = raizActual->ramas.primero;
		for (; selectorHijos; selectorHijos = selectorHijos->siguiente)
			compararBajoNum(selectorHijos->nodo, raizActual, listaArticulacion);
	}
}
void arbol_Grafo::datosNumBajoStr(nodoArbolGrafo* raizActual, string* linea, nodoArbolGrafo* nodoPadre) {
	if (raizActual) {
		stringstream ssNum(""), ssBajo("");
		string strNum, strBajo;
		nodoLista_arbolGrafo* selector = raizActual->ramas.primero;

		ssNum << raizActual->Num;
		ssBajo << raizActual->Bajo;
		strNum = ssNum.str();
		strBajo = ssBajo.str();

		if (nodoPadre)
			*linea = (*linea) + strNum + ", " + strBajo + "\t" + nodoPadre->valor->nombreCiudad + "->" + raizActual->valor->nombreCiudad + "\n";
		else
			*linea = (*linea) + strNum + ", " + strBajo + "\t" + raizActual->valor->nombreCiudad + "\n";

		while (selector) {
			datosNumBajoStr(selector->nodo, linea, raizActual);
			selector = selector->siguiente;
		}
	}
}
void arbol_Grafo::generarAristasRetroceso(nodoArbolGrafo* raizActual, Lista_arbolGrafo* nodosRetroceso, nodoArbolGrafo* nodoPadre) {
	if (raizActual) {
		nodoLista_arbolGrafo* selectorHoja = raizActual->ramas.primero;


		if (!nodosRetroceso->listaVacia()) {
			//Verifica si tiene un padre anterior al actual
			nodoLista_arbolGrafo* selectorRetroceso;
			NodoAdyacencia* selectorAdyacencia = raizActual->valor->listaAdyacencia;

			while (selectorAdyacencia) {
				selectorRetroceso = nodosRetroceso->primero;

				while (selectorRetroceso) {
					if (selectorRetroceso->nodo->valor == selectorAdyacencia->raizDirector && selectorRetroceso->nodo != nodoPadre)
						raizActual->aristaRetroceso.insertarNodo(selectorRetroceso->nodo);
					selectorRetroceso = selectorRetroceso->siguiente;
				}
				selectorAdyacencia = selectorAdyacencia->siguienteAdy;
			}
		}

		//Ingresa como nuevo padre para comparar
		nodosRetroceso->insertarNodo(raizActual);

		for (; selectorHoja; selectorHoja = selectorHoja->siguiente)
			generarAristasRetroceso(selectorHoja->nodo, nodosRetroceso, raizActual);
	}
}

// **************************************
// *	PILA SIMPLE	(Ptos Articulacion)	*
// **************************************

void pilaSimple_Grafo::push(NodoVertice* valor) {
	if (!tope)
		tope = new nodoPila(valor);
	else {
		nodoPila* nuevo = new nodoPila(valor);
		nuevo->siguiente = tope;
		tope = nuevo;
	}
}
nodoPila* pilaSimple_Grafo::pop() {
	nodoPila* aux = NULL;
	if (tope) {
		aux = tope;
		tope = tope->siguiente;
	}
	return aux;
}

// **********************
// *	LISTA SIMPLE	*
// **********************

listaSimple_Grafo::~listaSimple_Grafo() {
	nodoLista_Grafo* aux;
	while (primero) {
		aux = primero;
		primero = primero->siguiente;

		delete aux;
	}
	primero = NULL;
}
void listaSimple_Grafo::insertarInicio(NodoVertice* valor) {
	if (!primero)
		primero = new nodoLista_Grafo(valor);
	else {
		nodoLista_Grafo* aux = new nodoLista_Grafo(valor);

		aux->siguiente = primero;
		primero = aux;
	}
}
void listaSimple_Grafo::insertarFinal(int factor) {
	if (!primero)
		primero = new nodoLista_Grafo(factor);
	else {
		nodoLista_Grafo* aux = primero;
		while (aux->siguiente)
			aux = aux->siguiente;
		aux->siguiente = new nodoLista_Grafo(factor);
	}
}
void listaSimple_Grafo::insertarFinal(NodoVertice* valor) {
	if (!primero)
		primero = new nodoLista_Grafo(valor);
	else {
		nodoLista_Grafo* aux = primero;
		while (aux->siguiente)
			aux = aux->siguiente;
		aux->siguiente = new nodoLista_Grafo(valor);
	}
}
void listaSimple_Grafo::borrarInicio() {
	nodoLista_Grafo* aux = primero;
	primero = primero->siguiente;
	delete aux;
}
void listaSimple_Grafo::borrarFinal() {
	nodoLista_Grafo* selector = primero;
	nodoLista_Grafo* aux = selector;
	while (selector) {
		if (!selector->siguiente)
			break;
		aux = selector;
		selector = selector->siguiente;
	}
	if (aux)
		aux->siguiente = NULL;

	if (selector == primero) {
		delete primero;
		primero = NULL;
	}
	else
		delete selector;
}
nodoLista_Grafo* listaSimple_Grafo::obtenerFinal() {
	nodoLista_Grafo* selector = primero;
	while (selector) {
		if (!selector->siguiente)
			break;
		selector = selector->siguiente;
	}
	return selector;
}
void listaSimple_Grafo::borrarPosicion(int posicion) {
	if (posicion == 0)
		borrarInicio();
	else {
		nodoLista_Grafo* aux = primero;
		nodoLista_Grafo* temp;
		for (int i = 1; i < posicion; i++)
			aux = aux->siguiente;

		temp = aux->siguiente;
		aux->siguiente = temp->siguiente;
		delete temp;
	}
}

// **************************
// *	ESTRUCTURA GRAFO	*
// **************************

estructuraGrafo::~estructuraGrafo() {

	//Eliminar nodos directores y nodos adyacentes
	NodoVertice* selector;
	NodoAdyacencia* aux, * aux2;

	while (GrafoPrimero) {
		selector = GrafoPrimero;
		aux = selector->listaAdyacencia;

		while (aux) {
			aux2 = aux;
			aux = aux->siguienteAdy;
			delete aux2;
		}

		GrafoPrimero = GrafoPrimero->sigVertice;
		delete selector;
	}
}
int estructuraGrafo::cantidadVertices() {
	NodoVertice* selector = GrafoPrimero;
	int contador = 0;

	while (selector) {
		contador++;
		selector = selector->sigVertice;
	}
	return contador;
}
bool estructuraGrafo::existeCiclo(NodoVertice* verticeOrigen, NodoVertice* verticeDestino) {
	if (verticeDestino && verticeOrigen) {
		listaSimple_Grafo* verticesResueltos;
		NodoAdyacencia* selectorAdyacente = verticeDestino->listaAdyacencia;
		verticeDestino->visitado = true;

		while (selectorAdyacente) {
			if (!selectorAdyacente->raizDirector->visitado) {
				if (selectorAdyacente->raizDirector == verticeOrigen)
					return true;

				if (existeCiclo(verticeOrigen, selectorAdyacente->raizDirector))
					return true;
			}
			selectorAdyacente = selectorAdyacente->siguienteAdy;
		}
	}
	return false;
}
NodoVertice* estructuraGrafo::buscarVertice(int verticeBuscado) {
	NodoVertice* selector = GrafoPrimero;

	while (selector) {
		if (selector->codigoCiudad == verticeBuscado)
			return selector;
		selector = selector->sigVertice;
	}
	return 0;
}
void estructuraGrafo::actualizarVisitadoProcesado() {
	NodoVertice* selector = GrafoPrimero;

	while (selector) {
		selector->procesado = selector->visitado = false;
		selector = selector->sigVertice;
	}
}
void estructuraGrafo::insertarVertice(int codigoCiudad, string nombre) {
	if (!buscarVertice(codigoCiudad)) {
		NodoVertice* nuevoVertice = new NodoVertice(codigoCiudad, nombre);
		nuevoVertice->sigVertice = GrafoPrimero;
		GrafoPrimero = nuevoVertice;
	}
}
void estructuraGrafo::insertarArista(int vertice_Origen, int vertice_Destino, int factor) {
	NodoVertice* nodo_Origen = buscarVertice(vertice_Origen);
	NodoVertice* nodo_Destino = buscarVertice(vertice_Destino);

	if (nodo_Origen && nodo_Destino) {
		NodoAdyacencia* adyacente1 = new NodoAdyacencia(nodo_Origen);
		NodoAdyacencia* adyacente2 = new NodoAdyacencia(nodo_Destino);

		adyacente1->siguienteAdy = nodo_Destino->listaAdyacencia;
		adyacente2->siguienteAdy = nodo_Origen->listaAdyacencia;
		adyacente1->factorPeso = adyacente2->factorPeso = factor;

		nodo_Origen->listaAdyacencia = adyacente2;
		nodo_Destino->listaAdyacencia = adyacente1;
	}
}
void estructuraGrafo::algoritmo_Prim() {
	//Coloca el estado visitado de los vertices en false
	actualizarVisitadoProcesado();
	remove("Algoritmo_Prim.txt");

	// --- Iniciar modos para el archivo ---
	fstream archivoGrafo;
	archivoGrafo.open("Algoritmo_Prim.txt", ios::app);
	string nombreVertice1, nombreVertice2, strCosteMinimo, lineaCompleta;
	stringstream ssCosteMinimo;

	archivoGrafo << "Arbol de expansion minima:\n";
	// -------------------------------------

	//Inicia el conjunto W (Visitados)
	GrafoPrimero->visitado = true;
	listaSimple_Grafo listaVisitados;
	listaVisitados.insertarInicio(GrafoPrimero);

	//Selecciona los vertices visitados y sus adyacencias
	nodoLista_Grafo* selectorLista;
	NodoVertice* verticeSeleccionado;
	NodoVertice* verticeMenor = 0;
	NodoAdyacencia* NodoAdy_Seleccionado;
	unsigned int menorValor;
	unsigned int costeMinimo = 0;
	bool continuarAlgoritmo = true;

	//Ciclo del algoritmo
	while (continuarAlgoritmo) {
		continuarAlgoritmo = false;

		//Inicia cada selector con el primero de los visitados
		selectorLista = listaVisitados.primero;
		verticeSeleccionado = selectorLista->valor;
		NodoAdy_Seleccionado = verticeSeleccionado->listaAdyacencia;

		//Menor valor en un numero "Infinito"
		menorValor = 0xFFFF;

		//Revisa todos los adyacentes de los vertices visitados, buscando el menor
		while (selectorLista) {
			if (NodoAdy_Seleccionado->factorPeso < menorValor && !(NodoAdy_Seleccionado->raizDirector->visitado)) {

				nombreVertice1 = verticeSeleccionado->nombreCiudad;
				menorValor = NodoAdy_Seleccionado->factorPeso;
				verticeMenor = NodoAdy_Seleccionado->raizDirector;
				continuarAlgoritmo = true;
			}
			NodoAdy_Seleccionado = NodoAdy_Seleccionado->siguienteAdy;

			if (!NodoAdy_Seleccionado) {
				selectorLista = selectorLista->siguiente;

				if (selectorLista) {
					verticeSeleccionado = selectorLista->valor;
					if (verticeSeleccionado)
						NodoAdy_Seleccionado = verticeSeleccionado->listaAdyacencia;
				}
			}
		}

		//Cambia el estado del menor a visitado y lo inserta en la lista
		if (continuarAlgoritmo) {
			verticeMenor->visitado = true;
			listaVisitados.insertarInicio(verticeMenor);
			costeMinimo += menorValor;

			//Colocar los valores para el archivo
			nombreVertice2 = verticeMenor->nombreCiudad;
			lineaCompleta = nombreVertice1 + "  ->  " + nombreVertice2 + "\n";
			archivoGrafo.write(lineaCompleta.data(), lineaCompleta.size());
		}
	}
	ssCosteMinimo << costeMinimo;
	strCosteMinimo = ssCosteMinimo.str();

	lineaCompleta = "\nCoste Minimo: " + strCosteMinimo;
	archivoGrafo.write(lineaCompleta.data(), lineaCompleta.size());

	archivoGrafo.close();
}
void estructuraGrafo::algoritmo_Kruskal() {
	if (GrafoPrimero) {
		actualizarVisitadoProcesado();
		remove("Algoritmo_Kruskal.txt");

		NodoVertice* selectorVertice;
		NodoVertice* selectorAux;
		NodoAdyacencia* selectorAdy;
		NodoVertice* tempVertice1;
		NodoVertice* tempVertice2;

		listaSimple_Grafo listaFactores;
		listaSimple_Grafo listaFactores_Orden;
		estructuraGrafo grafoTemporal;

		// --- Iniciar modos para el archivo ---
		fstream archivoGrafo;
		archivoGrafo.open("Algoritmo_Kruskal.txt", ios::app);
		string nombreVertice1, nombreVertice2, strCosteMinimo, lineaCompleta, lineaOrden;
		stringstream ssCosteMinimo;

		archivoGrafo << "Arbol de expansion minima:\n";
		// -------------------------------------

		//Guardamos todos los factores
		selectorVertice = GrafoPrimero;
		while (selectorVertice) {
			grafoTemporal.insertarVertice(selectorVertice->codigoCiudad, selectorVertice->nombreCiudad);
			selectorAdy = selectorVertice->listaAdyacencia;

			while (selectorAdy) {
				listaFactores.insertarFinal(selectorAdy->factorPeso);
				selectorAdy = selectorAdy->siguienteAdy;
			}
			selectorVertice = selectorVertice->sigVertice;
		}

		nodoLista_Grafo* selectorFactores;
		int indiceFactor;
		bool repetido = false;
		unsigned int menorFactor;

		//Ordenamos la lista de factores (Menor a mayor) y evitamos repetidos
		while (!listaFactores.listaVacia()) {
			indiceFactor = 0;
			menorFactor = 0xFFFF;

			selectorFactores = listaFactores.primero;
			for (int i = 0; selectorFactores; i++) {
				if (selectorFactores->factor < menorFactor) {
					menorFactor = selectorFactores->factor;
					indiceFactor = i;
				}
				selectorFactores = selectorFactores->siguiente;
			}
			if (!repetido)
				listaFactores_Orden.insertarFinal(menorFactor);

			repetido = !repetido;
			listaFactores.borrarPosicion(indiceFactor);
		}

		//Conectamos los vertices(Componentes conexas)
		int costeMinimo = 0;
		int costeActual;

		selectorVertice = GrafoPrimero;
		selectorAdy = selectorVertice->listaAdyacencia;

		costeActual = listaFactores_Orden.primero->factor;
		listaFactores_Orden.borrarInicio();

		while (!listaFactores_Orden.listaVacia() && selectorAdy) {
			if (selectorAdy->factorPeso == costeActual) {

				tempVertice1 = grafoTemporal.buscarVertice(selectorVertice->codigoCiudad);
				tempVertice2 = grafoTemporal.buscarVertice(selectorAdy->raizDirector->codigoCiudad);

				if ((!selectorVertice->visitado || !selectorAdy->raizDirector->visitado) || !existeCiclo(tempVertice1, tempVertice2)) {
					grafoTemporal.actualizarVisitadoProcesado();

					costeMinimo += costeActual;
					selectorVertice->visitado = selectorAdy->raizDirector->visitado = true;

					//Escritura en el archivo (AEM)
					nombreVertice1 = selectorVertice->nombreCiudad;
					nombreVertice2 = selectorAdy->raizDirector->nombreCiudad;
					lineaCompleta = nombreVertice1 + "  ->  " + nombreVertice2 + "\n";
					archivoGrafo.write(lineaCompleta.data(), lineaCompleta.size());

					lineaOrden += selectorVertice->nombreCiudad + ", " + selectorAdy->raizDirector->nombreCiudad + " SI" + "\n";
					//------------------------------

					//Inicia las aristas del grafo temporal
					grafoTemporal.insertarArista(selectorVertice->codigoCiudad, selectorAdy->raizDirector->codigoCiudad, costeActual);

					selectorVertice = GrafoPrimero;
					selectorAdy = selectorVertice->listaAdyacencia;

					costeActual = listaFactores_Orden.primero->factor;
					listaFactores_Orden.borrarInicio();
					continue;
				}
			}
			else if (selectorAdy->factorPeso == costeActual)
				lineaOrden += selectorVertice->nombreCiudad + ", " + selectorAdy->raizDirector->nombreCiudad + " NO" + "\n";

			selectorAdy = selectorAdy->siguienteAdy;

			if (!selectorAdy) {
				selectorVertice = selectorVertice->sigVertice;
				if (selectorVertice)
					selectorAdy = selectorVertice->listaAdyacencia;
				else {
					selectorVertice = GrafoPrimero;
					selectorAdy = selectorVertice->listaAdyacencia;

					costeActual = listaFactores_Orden.primero->factor;
					listaFactores_Orden.borrarInicio();
				}
			}
		}
		//Escribe el componentes conexas
		lineaOrden = "\nComp. Conexas:\n" + lineaOrden;
		archivoGrafo.write(lineaOrden.data(), lineaOrden.size());

		//Escribe el coste minimo
		ssCosteMinimo << costeMinimo;
		strCosteMinimo = ssCosteMinimo.str();

		lineaCompleta = "\nCoste Minimo: " + strCosteMinimo;
		archivoGrafo.write(lineaCompleta.data(), lineaCompleta.size());
		archivoGrafo.close();
	}
}
void estructuraGrafo::algoritmo_Dijkstra(int Origen, int Destino) {
	NodoVertice* vertice_Origen = buscarVertice(Origen);
	NodoVertice* vertice_Destino = buscarVertice(Destino);

	if (vertice_Destino && vertice_Origen) {
		//Coloca el estado visitado de los nodos en falso
		actualizarVisitadoProcesado();
		remove("Algoritmo_Dijkstra.txt");

		int distanciaTotal = 0;
		int cantidadVisitados = 1;
		int totalVertices = cantidadVertices();
		int cantidadInsertados = 0;
		unsigned int menorValor;
		nodoLista_Grafo* selectorVertices = NULL;
		nodoLista_Grafo* selectorDistancia = NULL;
		NodoAdyacencia* selectorAdy;
		NodoVertice* selectorMenor = NULL;

		//Lista de nodos resueltos/visitados
		//Lista de las distacias totales para cada vertice
		listaSimple_Grafo vectoresResueltos;
		listaSimple_Grafo distaciasTotales;
		listaSimple_Grafo vectoresTemporal;

		//Inicializo las listas desde el origen
		vertice_Origen->visitado = true;
		vectoresResueltos.insertarFinal(vertice_Origen);
		distaciasTotales.insertarFinal(distanciaTotal);

		// --- Iniciar modos para el archivo ---
		fstream archivoGrafo;
		archivoGrafo.open("Algoritmo_Dijkstra.txt", ios::app);
		string nombreVertice1, nombreVertice2, strDistMin, strDistTotal, lineaCompleta, costeFinal;
		stringstream ssDistMin, ssDistTotal, ssCosteFinal;

		archivoGrafo << "Dist.Min	Dist.Total	N. Resuelto	N. no Resuelto\n";
		// -------------------------------------

		while (true) {
			if (!selectorVertices) {
				selectorVertices = vectoresTemporal.primero;
				while (selectorVertices) {
					selectorVertices->valor->visitado = true;
					vectoresResueltos.insertarFinal(selectorVertices->valor);
					selectorVertices = selectorVertices->siguiente;
				}
				vectoresTemporal.~listaSimple_Grafo();

				if (vectoresResueltos.obtenerFinal()->valor == vertice_Destino)
					break;

				selectorVertices = vectoresResueltos.primero;
				selectorDistancia = distaciasTotales.primero;
				menorValor = 0xFFFF;
				cantidadInsertados = 0;
			}

			if (selectorVertices && selectorDistancia) {
				selectorAdy = selectorVertices->valor->listaAdyacencia;
				distanciaTotal = selectorDistancia->factor;
				selectorMenor = NULL;

				lineaCompleta = "";
				nombreVertice1 = selectorVertices->valor->nombreCiudad;
				while (selectorAdy) {
					ssDistMin.str("");
					ssDistTotal.str("");

					nombreVertice2 = selectorAdy->raizDirector->nombreCiudad;
					ssDistMin << selectorAdy->factorPeso;
					ssDistTotal << distanciaTotal;

					strDistMin = ssDistMin.str();	strDistTotal = ssDistTotal.str();

					if ((selectorAdy->factorPeso + distanciaTotal) <= menorValor && selectorAdy->raizDirector && !(selectorAdy->raizDirector->visitado)) {
						if (menorValor != 0xFFFF && (selectorAdy->factorPeso + distanciaTotal) != menorValor) {
							for (int i = 0; i < cantidadInsertados; i++) {
								vectoresTemporal.obtenerFinal()->valor->visitado = false;
								vectoresTemporal.borrarFinal();
								distaciasTotales.borrarFinal();
								cantidadVisitados--;
							}
							cantidadInsertados = 0;
						}
						menorValor = distanciaTotal + selectorAdy->factorPeso;
						selectorMenor = selectorAdy->raizDirector;
					}
					selectorAdy = selectorAdy->siguienteAdy;
					lineaCompleta += strDistMin + "\t\t" + strDistTotal + "\t\t" + nombreVertice1 + "\t" + nombreVertice2 + "\n";
				}
				archivoGrafo.write(lineaCompleta.data(), lineaCompleta.size());

				if (selectorMenor) {
					vectoresTemporal.insertarFinal(selectorMenor);
					distaciasTotales.insertarFinal(menorValor);
					cantidadVisitados++;
					cantidadInsertados++;
				}

				selectorVertices = selectorVertices->siguiente;
				selectorDistancia = selectorDistancia->siguiente;
			}
		}

		ssCosteFinal << distaciasTotales.obtenerFinal()->factor;
		costeFinal = ssCosteFinal.str();
		lineaCompleta = "\nCoste del recorrido: " + costeFinal;
		archivoGrafo.write(lineaCompleta.data(), lineaCompleta.size());

		archivoGrafo.close();
	}
	else
		std::cout << "Puntos inexistentes\n";
}
void estructuraGrafo::algoritmo_Articulacion() {
	actualizarVisitadoProcesado();
	remove("Algoritmo_Ptos_Articulacion.txt");

	//Lista para buscar los padres hoja
	listaSimple_Grafo listaArbol;

	//Arbol n-ario
	arbol_Grafo arbolGrafo;

	//Recorrido en Profundidad - Armas el arbol n-ario
	pilaSimple_Grafo pila_Profundidad;
	NodoVertice* verticeSelector = GrafoPrimero;
	NodoAdyacencia* adyacenciaSelector;
	NodoAdyacencia* auxAdy;
	bool agregadoArbol;

	//Ingresa el primer vertice a la pila
	verticeSelector->visitado = true;
	pila_Profundidad.push(verticeSelector);

	// --- Iniciar modos para el archivo ---
	fstream archivoGrafo;
	archivoGrafo.open("Algoritmo_Ptos_Articulacion.txt", ios::app);
	string verticePila = verticeSelector->nombreCiudad + "\n", linea_Arbol;

	archivoGrafo << "Pila de profundidad:\n";
	// -------------------------------------

	while (!pila_Profundidad.pilaVacia()) {

		//Selecciona el vertice desde la pila
		verticeSelector = pila_Profundidad.pop()->valor;

		verticeSelector->procesado = true;
		adyacenciaSelector = verticeSelector->listaAdyacencia;

		//Busca el nodo hoja mas reciente para ser padre del vertice actual
		if (listaArbol.listaVacia()) {
			arbolGrafo.insertarRama(verticeSelector, NULL);
			listaArbol.insertarInicio(verticeSelector);
		}
		else {
			agregadoArbol = false;
			nodoLista_Grafo* selectorLista = listaArbol.primero;
			while (selectorLista && !agregadoArbol) {
				auxAdy = verticeSelector->listaAdyacencia;

				while (auxAdy && !agregadoArbol) {
					if (auxAdy->raizDirector->codigoCiudad == selectorLista->valor->codigoCiudad) {
						arbolGrafo.insertarRama(verticeSelector, selectorLista->valor);
						listaArbol.insertarInicio(verticeSelector);
						agregadoArbol = true;
					}
					auxAdy = auxAdy->siguienteAdy;
				}
				selectorLista = selectorLista->siguiente;
			}
		}
		//Ingresa los nodos adyacentes NO VISITADOS a la pila
		while (adyacenciaSelector) {

			if (!adyacenciaSelector->raizDirector->visitado) {
				verticePila += adyacenciaSelector->raizDirector->nombreCiudad + "\n";
				adyacenciaSelector->raizDirector->visitado = true;
				pila_Profundidad.push(adyacenciaSelector->raizDirector);
			}
			adyacenciaSelector = adyacenciaSelector->siguienteAdy;
		}
	}
	archivoGrafo.write(verticePila.data(), verticePila.size());

	//Inicializar la variable num
	int num = 1;
	arbolGrafo.inicializarNum(arbolGrafo.raiz, &num);

	//Crear aristas de retroceso
	Lista_arbolGrafo listaRetroceso;
	arbolGrafo.generarAristasRetroceso(arbolGrafo.raiz, &listaRetroceso, NULL);

	//Inicializa los valores de Bajo
	Lista_arbolGrafo listaPadres;
	arbolGrafo.inicializarBajo(arbolGrafo.raiz, &listaPadres, NULL);

	//--- Escribir Bajo y Num en archivo ---
	linea_Arbol = "\nNum | Bajo\n";
	arbolGrafo.datosNumBajoStr(arbolGrafo.raiz, &linea_Arbol, NULL);
	archivoGrafo.write(linea_Arbol.data(), linea_Arbol.size());
	//--------------------------------------

	//Compara el Bajo(Hijo) >= Num(Padre) para encontrar pto Articulacion
	nodoLista_arbolGrafo* selectorHijo = arbolGrafo.raiz->ramas.primero;
	Lista_arbolGrafo listaArticulacion;

	for (; selectorHijo; selectorHijo = selectorHijo->siguiente)
		arbolGrafo.compararBajoNum(selectorHijo->nodo, NULL, &listaArticulacion);

	//Verifica si la Raiz es Pto Articulacion(tiene mas de 2 hijos)
	if (arbolGrafo.raiz->ramas.primero && arbolGrafo.raiz->ramas.primero->siguiente)
		listaArticulacion.insertarNodo(arbolGrafo.raiz);

	//Imprime los nodos de articulacion
	linea_Arbol = "\nPuntos de articulacion:\n";
	nodoLista_arbolGrafo* selector = listaArticulacion.primero;
	if (!selector)
		linea_Arbol += "No posee puntos de articulacion\n";

	for (; selector; selector = selector->siguiente)
		linea_Arbol += selector->nodo->valor->nombreCiudad + ", ";

	archivoGrafo.write(linea_Arbol.data(), linea_Arbol.size());
	archivoGrafo.close();
}