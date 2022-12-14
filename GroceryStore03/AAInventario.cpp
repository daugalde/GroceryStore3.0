#include "AAInventario.h"

// ****************************************
// *  ARBOL DOBLE AA DE INVENTARIOS .CPP  *
// ****************************************

nodoBinario_AA_Inventario* arbolBinario_AA_Inventario::buscarInv(nodoBinario_AA_Inventario* raiz, int CodigoMarca) {
    if (!raiz)
        return 0;
    else if (raiz->CodigoMarca == CodigoMarca)
        return raiz;
    else {
        if (CodigoMarca < raiz->CodigoMarca)
            buscarInv(raiz->izq, CodigoMarca);
        else
            buscarInv(raiz->der, CodigoMarca);
    }
}

void arbolBinario_AA_Inventario::actuializarStock(nodoBinario_AA_Inventario* raiz, int CodigoMarca, int cantidad) {
    if (!raiz) {

        //cout << "\n Inventario Actualizado\n";
    }
    else if (raiz->CodigoMarca == CodigoMarca) {

        //cout << "\n  codigoMarca " << CodigoMarca << "  ha sido actualizado";
        raiz->setCantStock(cantidad);
    }
    else {
        if (CodigoMarca < raiz->CodigoMarca)
            actuializarStock(raiz->izq, CodigoMarca, cantidad);
        else
            actuializarStock(raiz->der, CodigoMarca, cantidad);
    }
}

arbolBinario_AA_Inventario::arbolBinario_AA_Inventario() {
    raiz = NULL;
}

arbolBinario_AA_Inventario::~arbolBinario_AA_Inventario() {
    eliminarArbol(&(this->raiz));
}
void arbolBinario_AA_Inventario::eliminarArbol(nodoBinario_AA_Inventario** raiz) {
    if (*raiz) {
        eliminarArbol(&((*raiz)->izq));
        eliminarArbol(&((*raiz)->der));
        delete* raiz;
    }
}
void arbolBinario_AA_Inventario::eliminarArbol(nodoBinario_AA_Inventario** raiz) {
    if (*raiz) {
        if (!((*raiz)->izq) && !((*raiz)->der))
            delete* raiz;
        else {
            eliminarArbol(&((*raiz)->izq));
            eliminarArbol(&((*raiz)->der));
            delete* raiz;
        }
    }
}

void arbolBinario_AA_Inventario::InsertarNodoAA(nodoBinario_AA_Inventario** raiz, int CodigoPasillo, int CodigoProducto, int CodigoMarca, string nombre, int CantStock, int CodCan, int nivel) {
    if (!(*raiz) || !((*raiz)->izq))
        insertarDerecho(raiz, CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan, nivel);
    else {
        if (CodigoMarca > (*raiz)->CodigoMarca)
            InsertarNodoAA(&((*raiz)->der), CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan, (*raiz)->nivel + 1);

        else
            InsertarNodoAA(&((*raiz)->izq), CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan, (*raiz)->nivel + 1);
    }
    if ((*raiz)->izq)
        if ((*raiz)->nivel == (*raiz)->izq->nivel)
            giro(raiz);

    if ((*raiz)->der)
        if ((*raiz)->der->der && ((*raiz)->nivel == (*raiz)->der->der->nivel))
            reparto(raiz);
}

void arbolBinario_AA_Inventario::insertarDerecho(nodoBinario_AA_Inventario** raiz, int CodigoPasillo, int CodigoProducto, int CodigoMarca, string nombre, int CantStock, int CodCan, int nivel) {
    if (!(*raiz)) {
        *raiz = new nodoBinario_AA_Inventario(CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan);
        (*raiz)->nivel = nivel;
    }
    else {
        if (CodigoMarca > (*raiz)->CodigoMarca)
            insertarDerecho(&((*raiz)->der), CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan, nivel);
        else {
            nodoBinario_AA_Inventario* nuevo = new nodoBinario_AA_Inventario(CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan);
            nuevo->nivel = nivel;

            nuevo->der = *raiz;
            (*raiz) = nuevo;
        }
    }
}

void arbolBinario_AA_Inventario::InsertarNodo(int CodigoPasillo, int CodigoProducto, int CodigoMarca, string nombre, int CantStock, int CodCan) {
    if (!(this->raiz)) {
        InsertarNodoAA(&(this->raiz), CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan, 0);
    }
    else {
        InsertarNodoAA(&(this->raiz), CodigoPasillo, CodigoProducto, CodigoMarca, nombre, CantStock, CodCan, this->raiz->nivel);

    }
}

void arbolBinario_AA_Inventario::reparto(nodoBinario_AA_Inventario** raiz) {
    nodoBinario_AA_Inventario* centroAux = (*raiz)->der;

    (*raiz)->der = centroAux->izq;
    centroAux->izq = *raiz;

    centroAux->nivel--;

    (*raiz) = centroAux;
}

void arbolBinario_AA_Inventario::giro(nodoBinario_AA_Inventario** raiz) {
    nodoBinario_AA_Inventario* nuevaRaiz = (*raiz)->izq;

    (*raiz)->izq = nuevaRaiz->der;
    nuevaRaiz->der = (*raiz);

    (*raiz) = nuevaRaiz;
}
void arbolBinario_AA_Inv::borrarNodo(int codigoRuta) {
    borrarAA(&(this->raiz), codigoRuta);
}

void arbolBinario_AA_Inventario::borrarAA(nodoBinario_AA_Inventario** raiz, int codigoMarca) {
    if (*raiz) {
        if (codigoMarca < (*raiz)->CodigoMarca) {
            borrarAA(&((*raiz)->izq), codigoMarca);
        }
        else if (codigoMarca > (*raiz)->CodigoMarca) {
            borrarAA(&((*raiz)->der), codigoMarca);
        }
        else if (codigoMarca == (*raiz)->CodigoMarca) {

            //Caso 1: 0 hijos
            if (!(*raiz)->izq && !(*raiz)->der) {
                delete* raiz;
                *raiz = NULL;
            }

            //Caso 2: 1 hijo(Solo existe el hijo derecho)
            else if (!(*raiz)->izq && (*raiz)->der) {
                nodoBinario_AA_Inventario* aux = *raiz;
                *raiz = aux->der;
                delete aux;
            }
            //Caso 3: 2 hijos
            else if ((*raiz)->izq && (*raiz)->der) {
                antecesorBorrado(&((*raiz)->izq), raiz);
                if (!(*raiz)->izq)
                    decrementarNivel((*raiz)->der);

                if ((*raiz)->izq)
                    if ((*raiz)->nivel == (*raiz)->izq->nivel)
                        giro(raiz);

                if ((*raiz)->der)
                    if ((*raiz)->der->der && ((*raiz)->nivel == (*raiz)->der->der->nivel))
                        reparto(raiz);
            }
            return;
        }
        if (!(*raiz)->izq && (*raiz)->der)
            decrementarNivel((*raiz)->der);

        if ((*raiz)->izq)
            if ((*raiz)->nivel == (*raiz)->izq->nivel)
                giro(raiz);

        if ((*raiz)->der)
            if ((*raiz)->der->der && ((*raiz)->nivel == (*raiz)->der->der->nivel))
                reparto(raiz);

    }
}

void arbolBinario_AA_Inventario::antecesorBorrado(nodoBinario_AA_Inventario** nodoIzq, nodoBinario_AA_Inventario** raiz) {
    if ((*nodoIzq)->der) {
        antecesorBorrado(&((*nodoIzq)->der), raiz);

        //Tiene hijo izq y no hijo der(Incumple regla, toca giro)
        if ((*nodoIzq)->izq && !(*nodoIzq)->der) {
            decrementarNivel((*nodoIzq)->izq);
            giro(nodoIzq);
        }

        if ((*nodoIzq)->der)
            if ((*nodoIzq)->der->der && ((*nodoIzq)->nivel == (*nodoIzq)->der->der->nivel))
                reparto(nodoIzq);
    }
    else {
        (*raiz)->CodigoMarca = (*nodoIzq)->CodigoMarca;
        delete* nodoIzq;
        *nodoIzq = NULL;
    }
}

void arbolBinario_AA_Inventario::decrementarNivel(nodoBinario_AA_Inventario* raiz) {
    if (raiz) {
        decrementarNivel(raiz->izq);
        decrementarNivel(raiz->der);
        raiz->nivel--;
    }
}
