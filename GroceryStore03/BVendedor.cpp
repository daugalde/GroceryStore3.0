#include "BVendedor.h"

// ***********************************
// * ARBOL B DE VENDEDORES      .CPP *
// ***********************************


#define MAX 3
#define MIN 1

arbolbinario_b_Vendedor::~arbolbinario_b_Vendedor() {
	destruirArbol(this->raiz);
}

void arbolbinario_b_Vendedor::destruirArbol(nodoBinario_Vendedor* raiz) {
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

void arbolbinario_b_Vendedor::buscarNodo(int claveNueva, nodoBinario_Vendedor** P, bool* encontrado, int* K) {
	if (claveNueva < (*P)->claves[0]->CodVendedor) {
		*encontrado = false;
		*K = 0;
	}
	else {
		*K = (*P)->cuentas;

		while (claveNueva < (*P)->claves[(*K) - 1]->CodVendedor && (*K) > 1) {
			(*K) = (*K) - 1;
		}

		*encontrado = (claveNueva == (*P)->claves[(*K) - 1]->CodVendedor);
	}
}

void arbolbinario_b_Vendedor::empujar(int CodVendedor, string nombre, nodoBinario_Vendedor** R, bool* empujarArriba, informacionVendedor** Mdna, nodoBinario_Vendedor** X) {
	int K = 0;
	bool esta = false;

	if (!(*R)) {
		*empujarArriba = true;
		*Mdna = new informacionVendedor(CodVendedor, nombre);
		*X = NULL;
	}
	else {
		buscarNodo(CodVendedor, R, &esta, &K);
		if (!esta) {
			empujar(CodVendedor, nombre, &((*R)->ramas[K]), empujarArriba, Mdna, X);
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

void arbolbinario_b_Vendedor::meterHoja(informacionVendedor** X, nodoBinario_Vendedor** Xder, nodoBinario_Vendedor** P, int* K) {
	for (int I = ((*P)->cuentas - 1); I >= (*K); I--) {
		(*P)->claves[I + 1] = (*P)->claves[I];
		(*P)->ramas[I + 2] = (*P)->ramas[I + 1];
	}
	(*P)->claves[(*K)] = *X;
	(*P)->ramas[(*K) + 1] = *Xder;
	(*P)->cuentas = (*P)->cuentas + 1;
}

void arbolbinario_b_Vendedor::dividirNodo(informacionVendedor* X, nodoBinario_Vendedor* Xder, nodoBinario_Vendedor** P, int* K, informacionVendedor** Mda, nodoBinario_Vendedor** Mder) {
	int posmda = 0;
	if ((*K) <= (MIN + 1))
		posmda = MIN + 1;
	else
		posmda = MIN + 2;

	*Mder = new nodoBinario_Vendedor();
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

void arbolbinario_b_Vendedor::insertar(int CodVendedor, string nombre, nodoBinario_Vendedor** raiz) {
	bool empujarArriba = false;
	nodoBinario_Vendedor* Xr = NULL;
	nodoBinario_Vendedor* P = NULL;
	informacionVendedor*X;

	empujar(CodVendedor, nombre, raiz, &empujarArriba, &X, &Xr);
	if (empujarArriba) {
		P = new nodoBinario_Vendedor();
		P->cuentas = 1;
		P->claves[0] = X;
		P->ramas[0] = *raiz;
		P->ramas[1] = Xr;

		*raiz = P;
	}
}

void arbolbinario_b_Vendedor::insertarNodo(int CodVendedor, string nombre) {
	insertar(CodVendedor, nombre, &(this->raiz));
}

