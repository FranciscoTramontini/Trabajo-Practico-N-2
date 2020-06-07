#include "itree.h"
#include "cola.h"
#include "avl.h"
#include <stdlib.h>

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

	while ((*aux) != NULL) {
		if ((*aux)->extra < dato.b)
			(*aux)->extra = dato.b;
            /* actualiza el maximo a los nodos que visita */
		if ((*aux)->interval.a == dato.a){
            /* caso extremo izquierdo iguales */
			if ((*aux)->interval.b < dato.b)
				aux = &((*aux)->left);
            //Me parece que faltaria ver que no sean iguales, asi no lo agrego;
            //Me parece que con ese codigo comentado de abajo estaria.
            // else if ((*aux)->interval.b == dato.b)
            //     return;
			else
				aux = &((*aux)->right);
			}
		else if ((*aux)->interval.a > dato.a)
			aux = &((*aux)->left);
		else
			aux = &((*aux)->right);
	}
	(*aux) = (ITNodo*)malloc(sizeof(ITNodo));
	(*aux)->interval = dato;
	(*aux)->left = NULL;
	(*aux)->right = NULL;
	avl_balancear(nodo, dato);
    //avl_calcular_altura((*nodo));
    (*nodo)->altura = avl_calcular_altura((*nodo));
}

//anda mal. Rehacer.
// void itree_eliminar(ITree *nodo, Intervalo dato) {
// 	ITNodo **aux, **temp, *temporal;
// 	aux = nodo;
//
// 	while ((*aux)->interval.a != dato.a || (*aux)->interval.b != dato.b) {
// 		if ((*aux)->interval.a > dato.a)
// 			aux = &((*aux)->left);
// 		else
// 			aux = &((*aux)->right);
// 	}
// 	if ((*aux)->left != NULL && (*aux)->right != NULL) {
// 		temp = &((*aux)->right);
// 		while ((*temp)->left) {
// 			temp = &((*temp)->left);
// 		}
// 		(*aux)->interval = (*temp)->interval;
// 		aux = temp;
//     /* caso con dos hijos */
// 	}
// 	if ((*aux)->left == NULL && (*aux)->right == NULL) {
// 		free(*aux);
// 		(*aux) = NULL;
//     /* caso sin hijos */
// 	}
// 	else if ((*aux)->left == NULL) {
// 		temporal = (*aux);
// 		(*aux) = (*aux)->right;
// 		free(temporal);
//     /* caso hijo derecho */
// 	}
//     else {
// 		temporal = (*aux);
// 		(*aux) = (*aux)->left;
// 		free(temporal);
//     /* caso hijo izquierdo */
// 	}
//
// 	avl_balancear(nodo, dato);
// }

ITNodo* itree_intersectar(ITree *nodo, Intervalo dato) {
	ITNodo **aux;
	aux = nodo;

	if (nodo == NULL)
		return NULL; // Capaz esto lo podemos obviar, ya que si nodo es null no
                        // entra en el while, hay que verlo.
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
        visit(nodo->interval.a, nodo->interval.b, nodo->altura);
        itree_recorrer_dfs(nodo->right, visit);
    /* recorrido inorden */
    }
}

void itree_recorrer_bfs(ITree nodo, FuncionVisitante visit){
    Cola cola = cola_crear();
    ITree aux = nodo;
    //Podemos sacarlo y trabajar con nodo.
    while (aux != NULL) {
        visit(aux->interval.a, aux->interval.b, aux->altura);
        if (aux->left != NULL)
            cola_encolar(cola, aux->left);
        if (aux->right != NULL)
            cola_encolar(cola, aux->right);
        aux = cola_desencolar(cola);
    }
    //cola_destruir(cola);
    //itree_destruir(aux);
}
