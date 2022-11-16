#include "AAInventario.h"

// ****************************************
// *  ARBOL DOBLE AA DE INVENTARIOS .CPP  *
// ****************************************

nodoBinario_AA_Inventario* arbolBinario_AA_Inventario::buscarInv(nodoBinario_AA_Inventario* raiz, Object*obj) {
    if (!raiz)
        return 0;
    else if (raiz->getValue()->getId())
        return raiz;
    else {
        if (obj->getId()< raiz->getValue()->getId())
            buscarInv(raiz->izq,obj);
        else
            buscarInv(raiz->der, obj);
    }
}

void arbolBinario_AA_Inventario::actuializarStock(nodoBinario_AA_Inventario* raiz, Object*obj) {
    if (!raiz) {

        cout << "\n Inventario Actualizado\n";
    }
    else if (raiz->getValue() == obj) {

        cout << "\n  codigoMarca " << obj << "  ha sido actualizado";
        raiz->getValue()->getId();
    }
    else {
        if (obj->getId()< raiz->getValue()->getId())
            actuializarStock(raiz->izq, obj);
        else
            actuializarStock(raiz->der, obj);
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

void arbolBinario_AA_Inventario::eliminarArbolInner(nodoBinario_AA_Inventario** raiz) {
    if (*raiz) {
        if (!((*raiz)->izq) && !((*raiz)->der))
            delete* raiz;
        else {
            eliminarArbolInner(&((*raiz)->izq));
            eliminarArbolInner(&((*raiz)->der));
            delete* raiz;
        }
    }
}

void arbolBinario_AA_Inventario::InsertarNodoAA(nodoBinario_AA_Inventario** raiz, Object* obj, int nivel) {
    if (!(*raiz) || !((*raiz)->izq))
         insertarDerecho(raiz,obj, nivel);
     else {
         if (obj->getId() > (*raiz)->getValue()->getId())
            InsertarNodoAA(&((*raiz)->der), obj, (*raiz)->nivel + 1);
        else
             InsertarNodoAA(&((*raiz)->izq), obj, (*raiz)->nivel + 1);
     }
    if ((*raiz)->izq)
         if ((*raiz)->nivel == (*raiz)->izq->nivel)
            giro(raiz);
    
     if ((*raiz)->der)
        if ((*raiz)->der->der && ((*raiz)->nivel == (*raiz)->der->der->nivel))
            reparto(raiz);
}

void arbolBinario_AA_Inventario::insertarDerecho(nodoBinario_AA_Inventario** raiz, Object* obj, int nivel) {
    if (!(*raiz)) {
        *raiz = new nodoBinario_AA_Inventario(obj);
        (*raiz)->nivel = nivel;
    }
    else {
        if (obj->getId() > (*raiz)->getValue()->getId()) //CodigoMarca
            insertarDerecho(&((*raiz)->der), obj, nivel);
        else {
            nodoBinario_AA_Inventario* nuevo = new nodoBinario_AA_Inventario(obj);
            nuevo->nivel = nivel;

            nuevo->der = *raiz;
            (*raiz) = nuevo;
        }
    }
}

void arbolBinario_AA_Inventario::InsertarNodo(Object* obj) {
    if (!(this->raiz)) {
        InsertarNodoAA(&(this->raiz), obj,0);
    }
    else {
        InsertarNodoAA(&(this->raiz), obj, this->raiz->nivel);
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
void arbolBinario_AA_Inventario::borrarNodo( Object* obj) {
    borrarAA(&(this->raiz), obj);
}

void arbolBinario_AA_Inventario::borrarAA(nodoBinario_AA_Inventario** raiz, Object*obj) {
    if (*raiz) {
        if (obj->getId() > (*raiz)->getValue()->getId() ){
            borrarAA(&((*raiz)->izq), obj);
        }
        else if (obj->getId() >(*raiz)->getValue()->getId()) {
            borrarAA(&((*raiz)->der), obj);
        }
        else if (obj== (*raiz)->getValue()) {

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
        (*raiz)->getValue()->getId(); (*nodoIzq)->getValue()->getId();
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