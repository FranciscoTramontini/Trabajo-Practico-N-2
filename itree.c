#include "itree.h"
#include "cola.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>

ITree itree_crear() {
    return NULL;
}

void itree_destruir(ITree nodo) {
    if (nodo != NULL){
        itree_destruir(nodo->left);
        itree_destruir(nodo->right);
        free(nodo);
    }
}

void itree_insertar(ITree *nodo, Intervalo dato) {
	ITNodo **aux = nodo;

	if ((*aux) == NULL) {
		(*aux) = (ITNodo *)malloc(sizeof(ITNodo));
        assert(aux);
		(*aux)->interval = dato;
		(*aux)->altura = 1;
		(*aux)->left = NULL;
		(*aux)->right = NULL;
        itree_actualizar_max((*nodo));
		return;
	} else {
		if (dato.a < (*aux)->interval.a ||
            (dato.a == (*aux)->interval.a && dato.b < (*aux)->interval.b))
			itree_insertar(&((*aux)->left), dato);
        else if (dato.a == (*aux)->interval.a && dato.b == (*aux)->interval.b)
            return;
		else
			itree_insertar(&((*aux)->right), dato);

		itree_balancear(aux);
		itree_actualizar_altura((*aux));
        itree_actualizar_max((*aux));
	  }
}

void itree_eliminar(ITree *nodo, Intervalo dato) {
	ITNodo *temp;
	ITNodo **aux = nodo;

	if ((*aux) == NULL) return;

	if (dato.a < (*aux)->interval.a ||
        (dato.a == (*aux)->interval.a && dato.b < (*aux)->interval.b)) {
		itree_eliminar(&((*aux)->left), dato);
    }
	else if (dato.a > (*aux)->interval.a ||
             (dato.a == (*aux)->interval.a && dato.b > (*aux)->interval.b)) {
		itree_eliminar(&((*aux)->right), dato);
    }
	else {
		if ((*aux)->left != NULL && (*aux)->right != NULL) {
			ITNodo **temp = &((*aux)->right);
			while ((*temp)->left)
				temp = &((*temp)->left);

			(*aux)->interval = (*temp)->interval;
			aux = temp;
		/* con dos hijos */
		}
		if ((*aux)->left == NULL && (*aux)->right == NULL) {
			free((*aux));
			(*aux) = NULL;
		/* sin hijos */
		}
		else if ((*aux)->left == NULL) {
			temp = (*aux);
			(*aux) = (*aux)->right;
			free(temp);
		/* hijo derecho */
		}
		else {
			temp = (*aux);
			(*aux) = (*aux)->left;
			free(temp);
		/* hijo izquierdo */
		}
	}
    itree_actualizar_max((*nodo));
	itree_actualizar_altura((*nodo));
	itree_balancear(nodo);
}

ITNodo* itree_intersectar(ITree *nodo, Intervalo dato) {
	ITNodo **aux = nodo;

	while ((*aux) != NULL) {
		if (dato.b >= (*aux)->interval.a && dato.a <= (*aux)->interval.b)
			return *aux;
		else if ((*aux)->left != NULL && dato.a <= (*aux)->left->extra)
			aux = &((*aux)->left);
		else
			aux = &((*aux)->right);
	}
	return NULL;
}

void itree_recorrer_dfs(ITree nodo, FuncionVisitante visit) {
    if (nodo != NULL) {
        itree_recorrer_dfs(nodo->left, visit);
        visit(nodo->interval.a, nodo->interval.b, nodo->extra, nodo->altura);
        itree_recorrer_dfs(nodo->right, visit);
    /* recorrido inorden */
    }
}

void itree_recorrer_bfs(ITree nodo, FuncionVisitante visit){
    Cola cola = cola_crear();
    ITree aux = nodo;

    while (aux != NULL) {
        visit(aux->interval.a, aux->interval.b, aux->extra, aux->altura);
        if (aux->left != NULL)
            cola_encolar(cola, aux->left);
        if (aux->right != NULL)
            cola_encolar(cola, aux->right);
        aux = cola_desencolar(cola);
    }
    cola_destruir(cola);
    itree_destruir(aux);
}

int itree_altura(ITree nodo) {
	if (nodo == NULL)
		return 0;
	else
		return nodo->altura;
}

void itree_actualizar_altura(ITree nodo) {
	if (nodo != NULL)
		nodo->altura = fmax(itree_altura(nodo->left),
                            itree_altura(nodo->right)) + 1;
}

void itree_actualizar_max(ITree nodo) {
	if (nodo != NULL){
		if (nodo->left == NULL) {
			if (nodo->right != NULL)
				nodo->extra = fmax(nodo->right->extra,nodo->interval.b);
			/* caso extremos izquierdos iguales, sin hijo izquierdo
			 * con hijo derecho */
			else
				nodo->extra = nodo->interval.b;
			/* caso sin hijos */
		}
		else if (nodo->left != NULL && nodo->right == NULL)
			nodo->extra = fmax(nodo->left->extra,nodo->interval.b);
		/* caso solo hijo izquierdo */
		else
			nodo->extra = fmax(nodo->interval.b,
                          fmax(nodo->left->extra,nodo->right->extra));
        /* caso dos hijos */
		}
}

int itree_balance_factor(ITree nodo) {
	return itree_altura(nodo->right) - itree_altura(nodo->left);
}

void itree_rotacion_simple_derecha(ITree *nodo) {
	ITNodo *aux;

	aux = (*nodo)->right;
	(*nodo)->right = aux->left;
	aux->left = (*nodo);
	/* rotacion */

	itree_actualizar_altura((*nodo));
	itree_actualizar_altura(aux);
	/* calculo de alturas para los nodos intercambiados */

	itree_actualizar_max((*nodo));
	itree_actualizar_max(aux);
	/* calculo del maximo valor del intervalo en los nodos cambiados */

	(*nodo) = aux;
}

void itree_rotacion_simple_izquierda(ITree *nodo) {
	ITNodo *aux;

	aux = (*nodo)->left;
	(*nodo)->left = aux->right;
	aux->right = (*nodo);
	/* rotacion */

	itree_actualizar_altura((*nodo));
	itree_actualizar_altura(aux);
	/* calculo de alturas para los nodos intercambiados */

	itree_actualizar_max((*nodo));
	itree_actualizar_max(aux);
	/* calculo del maximo valor del intervalo en los nodos intercambiados */

	(*nodo) = aux;
}

void itree_rotacion_doble_izquierda(ITree *nodo) {
	itree_rotacion_simple_derecha(&((*nodo)->left));
	itree_rotacion_simple_izquierda(nodo);
}

void itree_rotacion_doble_derecha(ITree *nodo) {
	itree_rotacion_simple_izquierda(&((*nodo)->right));
	itree_rotacion_simple_derecha(nodo);
}

// Ver si swicth es buena opcion o buscar otra.
void itree_balancear(ITree *nodo) {
	if ((*nodo) != NULL) {
		switch (itree_balance_factor((*nodo))) {
			case 2:
			if (itree_altura((*nodo)->right->right) >=
                        itree_altura((*nodo)->right->left)) {
				itree_rotacion_simple_derecha(nodo);
            }
			else
				itree_rotacion_doble_derecha(nodo);
			break;
			case -2:
			if (itree_altura((*nodo)->left->left) >=
                        itree_altura((*nodo)->left->right)) {
				itree_rotacion_simple_izquierda(nodo);
            }
			else
				itree_rotacion_doble_izquierda(nodo);
			break;
		}
	}
}
