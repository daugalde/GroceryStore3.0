#include "BAdmin.h"

// ***********************************
// * ARBOL B DE ADMINISTRADORES .CPP *
// ***********************************


#define MAX 3
#define MIN 1

arbolbinario_b_Admin::~arbolbinario_b_Admin() {
	destruirArbol(this->raiz);
}

void arbolbinario_b_Admin::destruirArbol(nodoBinario_Admin* raiz) {
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

void arbolbinario_b_Admin::buscarNodo(int claveNueva, nodoBinario_Admin** P, bool* encontrado, int* K) {
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

void arbolbinario_b_Admin::empujar(int CodAdministrador, string nombre, nodoBinario_Admin** R, bool* empujarArriba, informacionAdministrador** Mdna, nodoBinario_Admin** X) {
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

void arbolbinario_b_Admin::meterHoja(informacionAdministrador** X, nodoBinario_Admin** Xder, nodoBinario_Admin** P, int* K) {
	for (int I = ((*P)->cuentas - 1); I >= (*K); I--) {
		(*P)->claves[I + 1] = (*P)->claves[I];
		(*P)->ramas[I + 2] = (*P)->ramas[I + 1];
	}
	(*P)->claves[(*K)] = *X;
	(*P)->ramas[(*K) + 1] = *Xder;
	(*P)->cuentas = (*P)->cuentas + 1;
}

void arbolbinario_b_Admin::dividirNodo(informacionAdministrador* X, nodoBinario_Admin* Xder, nodoBinario_Admin** P, int* K, informacionAdministrador** Mda, nodoBinario_Admin** Mder) {
	int posmda = 0;
	if ((*K) <= (MIN + 1))
		posmda = MIN + 1;
	else
		posmda = MIN + 2;

	*Mder = new nodoBinario_Admin();
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

void arbolbinario_b_Admin::insertar(int CodAdministrador, string nombre, nodoBinario_Admin** raiz) {
	bool empujarArriba = false;
	nodoBinario_Admin* Xr = NULL;
	nodoBinario_Admin* P = NULL;
	informacionAdministrador* X;

	empujar(CodAdministrador, nombre, raiz, &empujarArriba, &X, &Xr);
	if (empujarArriba) {
		P = new nodoBinario_Admin();
		P->cuentas = 1;
		P->claves[0] = X;
		P->ramas[0] = *raiz;
		P->ramas[1] = Xr;

		*raiz = P;
	}
}

void arbolbinario_b_Admin::insertarNodo(int CodAdministrador, string nombre) {
	insertar(CodAdministrador, nombre, &(this->raiz));
}

informacionAdministrador* arbolbinario_b_Admin::buscarAdmins(nodoBinario_Admin** raiz, int contrasena) {
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
