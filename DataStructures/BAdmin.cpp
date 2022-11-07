#include "BAdmin.h"

// ***********************************
// * ARBOL B DE ADMINISTRADORES .CPP *
// ***********************************


#define MAX 3
#define MIN 1

arbolbinario_b::~arbolbinario_b() {
	destruirArbol(this->raiz);
}

void arbolbinario_b::destruirArbol(nodoArbolBinario_B* raiz) {
	if (raiz) {
		if (!(raiz->ramas[0]))
			delete raiz;
		else {
			for (int i = 0; i < 5; i++) {
				if (raiz->ramas[i])
					destruirArbol(raiz->ramas[i]);
				else {
					delete raiz;
					break;
				}
			}
		}
	}
}

void arbolbinario_b::buscarNodo(int claveNueva, nodoArbolBinario_B** P, bool* encontrado, int* K) {
	if (claveNueva < (*P)->claves[0]->CodAdministrador) {
		*encontrado = false;
		*K = 0;
	}
	else {
		*K = (*P)->cuentas;

		while (claveNueva < (*P)->claves[(*K) - 1]->CodAdministrador && (*K) > 1) {
			(*K) = (*K) - 1;
		}

		*encontrado = (claveNueva == (*P)->claves[(*K) - 1]->CodAdministrador);
	}
}

void arbolbinario_b::empujar(int CodAdministrador, string nombre, nodoArbolBinario_B** R, bool* empujarArriba, informacionAdministrador** Mdna, nodoArbolBinario_B** X) {
	int K = 0;
	bool esta = false;

	if (!(*R)) {
		*empujarArriba = true;
		*Mdna = new informacionAdministrador(CodAdministrador, nombre);
		*X = NULL;
	}
	else {
		buscarNodo(CodAdministrador, R, &esta, &K);
		if (!esta) {
			empujar(CodAdministrador, nombre, &((*R)->ramas[K]), empujarArriba, Mdna, X);
			if (*empujarArriba) {
				if ((*R)->cuentas < (MAX + 1)) {
					*empujarArriba = false;
					meterHoja(Mdna, X, R, &K);
				}
				else {
					*empujarArriba = true;
					dividirNodo(*Mdna, *X, R, &K, Mdna, X);
				}
			}
		}
	}
}

void arbolbinario_b::meterHoja(informacionAdministrador** X, nodoArbolBinario_B** Xder, nodoArbolBinario_B** P, int* K) {
	for (int I = ((*P)->cuentas - 1); I >= (*K); I--) {
		(*P)->claves[I + 1] = (*P)->claves[I];
		(*P)->ramas[I + 2] = (*P)->ramas[I + 1];
	}
	(*P)->claves[(*K)] = *X;
	(*P)->ramas[(*K) + 1] = *Xder;
	(*P)->cuentas = (*P)->cuentas + 1;
}

void arbolbinario_b::dividirNodo(informacionAdministrador* X, nodoArbolBinario_B* Xder, nodoArbolBinario_B** P, int* K, informacionAdministrador** Mda, nodoArbolBinario_B** Mder) {
	int posmda = 0;
	if ((*K) <= (MIN + 1))
		posmda = MIN + 1;
	else
		posmda = MIN + 2;

	*Mder = new nodoArbolBinario_B();
	for (int I = posmda; I < (MAX + 1); I++) {
		(*Mder)->claves[I - posmda] = (*P)->claves[I];
		(*Mder)->ramas[I - posmda + 1] = (*P)->ramas[I + 1];
	}

	(*Mder)->cuentas = (MAX + 1) - posmda;
	(*P)->cuentas = posmda;

	posmda = (*K) - posmda;
	if ((*K) <= MIN + 1)
		meterHoja(&X, &Xder, P, K);
	else
		meterHoja(&X, &Xder, Mder, &posmda);

	*Mda = (*P)->claves[((*P)->cuentas) - 1];
	(*Mder)->ramas[0] = (*P)->ramas[((*P)->cuentas)];

	(*P)->cuentas = (*P)->cuentas - 1;
}

void arbolbinario_b::insertar(int CodAdministrador, string nombre, nodoArbolBinario_B** raiz) {
	bool empujarArriba = false;
	nodoArbolBinario_B* Xr = NULL;
	nodoArbolBinario_B* P = NULL;
	informacionAdministrador* X;

	empujar(CodAdministrador, nombre, raiz, &empujarArriba, &X, &Xr);
	if (empujarArriba) {
		P = new nodoArbolBinario_B();
		P->cuentas = 1;
		P->claves[0] = X;
		P->ramas[0] = *raiz;
		P->ramas[1] = Xr;

		*raiz = P;
	}
}

void arbolbinario_b::insertarNodo(int CodAdministrador, string nombre) {
	insertar(CodAdministrador, nombre, &(this->raiz));
}

informacionAdministrador* arbolbinario_b::buscarAdmins(nodoArbolBinario_B** raiz, int contrasena) {
	if (*raiz) {
		int cuentasActuales = (*raiz)->cuentas;

		for (int i = 0; i < cuentasActuales; i++) {
			if (contrasena == (*raiz)->claves[i]->CodAdministrador)
				return (*raiz)->claves[i];

			else if (contrasena < (*raiz)->claves[i]->CodAdministrador)
				return buscarAdmins(&((*raiz)->ramas[i]), contrasena);

			else if (i == cuentasActuales - 1)
				return buscarAdmins(&((*raiz)->ramas[i + 1]), contrasena);
		}
	}
	return 0;
}

void arbolbinario_b::borrarNodo(int contrasena) {
	Eliminar(contrasena, &(this->raiz));
}

void arbolbinario_b::Eliminar(int contrasena, nodoArbolBinario_B** raiz) {
	bool Encontrado = true;
	nodoArbolBinario_B* P;

	EliminarRegistro(contrasena, &(*raiz), &Encontrado);
	if (!(Encontrado)) {
		cout << "el elemento no se encuentra en el árbol A-----A" << endl;
	}
	else {

		if ((*raiz)->cuentas == 0) {

			P = *raiz;
			*raiz = (*raiz)->ramas[0];
			delete (P);
		}
	}
}
void arbolbinario_b::EliminarRegistro(int contrasena, nodoArbolBinario_B** raiz, bool* Encontrado) {
	int K = 0;
	if (!(*raiz)) {
		*Encontrado = false;
	}
	else {
		buscarNodo(contrasena, raiz, &(*Encontrado), &K);
		if (*Encontrado) {
			if ((*raiz)->ramas[K - 1] == NULL) { //Las ramas estan indexadas desde 0 a Max, por lo que este nodo es hoja
				Quitar(raiz, &K);
			}

			// NO es hoja
			else {
				Sucesor(raiz, &K); // reemplaza Claves[K] por su sucesor

				EliminarRegistro((*raiz)->claves[K - 1]->CodAdministrador, &((*raiz)->ramas[K]), &(*Encontrado)); //Elimina la clave sucesora en su nodo

				//inconsistencia debe estar en el nodo
				if (!(Encontrado)) {
					cout << "Error en el proceso" << endl;
				}
			}
		}
		else { // No ha sido localizada la clave

			EliminarRegistro(contrasena, &((*raiz)->ramas[K]), Encontrado); ////////////////////// PRIMER parametro correcto?
			// Las llamadas recursivas retornan el control a este punto,
			// se comprueba que el nodo hijo mantenga un numero
			// claves igual o mayor que el minimo necesario
		}
		if (((*raiz)->ramas[K]) != NULL) {

			if ((*raiz)->ramas[K]->cuentas <= MIN) {

				Restablecer(raiz, &K);
			}
		}
	}
}

void arbolbinario_b::Quitar(nodoArbolBinario_B** P, int* K) {
	for (int J = *K; J < ((*P)->cuentas); J++) {

		(*P)->claves[J - 1] = (*P)->claves[J]; //Desplaza una posicion a la izquierda, con ello elimina la clave
		(*P)->ramas[J - 1] = (*P)->ramas[J];
	}
	(*P)->cuentas = ((*P)->cuentas) - 1;
}

void arbolbinario_b::Sucesor(nodoArbolBinario_B** P, int* K) {
	nodoArbolBinario_B* Q;

	Q = (*P)->ramas[*K];
	if (Q) {
		while (Q->ramas[0] != NULL) {
			Q = Q->ramas[0];
		}

		(*P)->claves[(*K) - 1] = Q->claves[0];
	}
}

void arbolbinario_b::Restablecer(nodoArbolBinario_B** P, int* K) {
	if (*K > 0) {
		if ((*P)->ramas[*K - 1]->cuentas > MIN + 1)
			MoverDerecha(P, K);
		else
			Combina(P, *K); // &(*K) si el parametro de Combina es int*
	}
	else { //solo tiene hermano derecho

		//Tiene mas claves que el minimo
		if ((*P)->ramas[1]->cuentas > MIN + 1)
			MoverIzquierda(P, 1);
		// NO PERMITE INT A INT*
		else
			Combina(P, 1);
	}
}

void arbolbinario_b::MoverDerecha(nodoArbolBinario_B** P, int* K) {
	//Hace hueco para meter la clave del padre
	for (int J = (*P)->ramas[*K]->cuentas; J >= (*K); J--) {

		(*P)->ramas[*K]->claves[J] = (*P)->ramas[*K]->claves[J - 1];
		(*P)->ramas[*K]->ramas[J + 1] = (*P)->ramas[*K]->ramas[J];
	}

	// Baja la clave del nodo padre
	(*P)->ramas[*K]->cuentas = (*P)->ramas[*K]->cuentas + 1;
	(*P)->ramas[*K]->ramas[1] = (*P)->ramas[*K]->ramas[0];
	(*P)->ramas[*K]->claves[(*K) - 1] = (*P)->claves[(*K) - 1];

	/*Ahora sube la clave desde el hermano izquierdo al nodo padre, para reemplazar la que bajo*/

	(*P)->claves[(*K) - 1] = (*P)->ramas[*K - 1]->claves[(*P)->ramas[(*K) - 1]->cuentas - 1];
	(*P)->ramas[*K]->ramas[0] = (*P)->ramas[*K - 1]->ramas[(*P)->ramas[(*K) - 1]->cuentas];
	(*P)->ramas[*K - 1]->cuentas = (*P)->ramas[*K - 1]->cuentas - 1;
}

void arbolbinario_b::MoverIzquierda(nodoArbolBinario_B** P, int K) {
	// Baja la clave del nodo padre 
	(*P)->ramas[K - 1]->cuentas = (*P)->ramas[K - 1]->cuentas + 1;
	(*P)->ramas[K - 1]->claves[(*P)->ramas[K - 1]->cuentas - 1] = (*P)->claves[K - 1];
	(*P)->ramas[K - 1]->ramas[(*P)->ramas[K - 1]->cuentas] = (*P)->ramas[K]->ramas[0];


	/*Ahora sube la clave desde el hermano derecho al nodo padre, para reemplazar la que bajo*/
	(*P)->claves[K - 1] = (*P)->ramas[K]->claves[0];
	(*P)->ramas[K]->cuentas = (*P)->ramas[K]->cuentas - 1;

	for (int J = 0; J <= (*P)->ramas[K]->cuentas; J++) {

		(*P)->ramas[K]->claves[J] = (*P)->ramas[K]->claves[J + 1];
		(*P)->ramas[K]->ramas[J] = (*P)->ramas[K]->ramas[J + 1];
	}
}

void arbolbinario_b::Combina(nodoArbolBinario_B** P, int K) {
	nodoArbolBinario_B* Q;
	Q = (*P)->ramas[K];

	//with (*P)->ramas[*K - 1]//hermano izquierdo

	(*P)->ramas[K - 1]->cuentas = (*P)->ramas[K - 1]->cuentas + 1;
	(*P)->ramas[K - 1]->claves[(*P)->ramas[K - 1]->cuentas - 1] = (*P)->claves[K - 1];// baja clave mediana desde el nodo padre
	(*P)->ramas[K - 1]->ramas[(*P)->ramas[K - 1]->cuentas] = Q->ramas[0];

	for (int J = 0; J < Q->cuentas; J++) {

		(*P)->ramas[K - 1]->cuentas = (*P)->ramas[K - 1]->cuentas + 1;
		(*P)->ramas[K - 1]->claves[(*P)->ramas[K - 1]->cuentas - 1] = Q->claves[J];
		(*P)->ramas[K - 1]->ramas[(*P)->ramas[K - 1]->cuentas] = Q->ramas[J + 1];
	}

	//Reajustadas las claves y ramas del nodo padre debido a que antes ascendio la clave K
	// With P

	for (int J = K; J <= (*P)->cuentas - 1; J++) {

		(*P)->claves[J - 1] = (*P)->claves[J];
		(*P)->ramas[J] = (*P)->ramas[J + 1];
	}
	(*P)->cuentas = (*P)->cuentas - 1;

	delete Q;
}