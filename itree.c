#include "itree.h"
#include "cola.h"
#include "bstree.h"
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
	ITNodo **aux;
	aux = nodo;
	while ((*aux) != NULL) {
		if ((*aux)->interval.a > dato.a)
			aux = &((*aux)->left);
		else
			aux = &((*aux)->right);
	}
	(*aux) = (ITNodo*)malloc(sizeof(ITNodo));
	(*aux)->interval = dato;
	(*aux)->left = NULL;
	(*aux)->right = NULL;
	bstree_balancear(nodo, dato);
}

void itree_eliminar(ITree *nodo, Intervalo dato) {
	ITNodo **aux, **temp, *temporal;
	aux = nodo;
	while ((*aux)->interval.a != dato.a || (*aux)->interval.b != dato.b) {
		if ((*aux)->interval.a > dato.a)
			aux = &((*aux)->left);
		else
			aux = &((*aux)->right);
	}
	if ((*aux)->left != NULL && (*aux)->right != NULL) {
		temp = &((*aux)->right);
		while ((*temp)->left) {
			temp = &((*temp)->left);
		}
		(*aux)->interval = (*temp)->interval;
		aux = temp;
	}
	if ((*aux)->left == NULL && (*aux)->right == NULL) {
		free(*aux);
		(*aux) = NULL;
	}
	else if ((*aux)->left == NULL) {
		temporal = (*aux);
		(*aux) = (*aux)->right;
		free(temporal);
	} else {
		temporal = (*aux);
		(*aux) = (*aux)->left;
		free(temporal);
	  }
	bstree_balancear(nodo, dato);
}

void itree_recorrer_dfs(ITree nodo, FuncionVisitante visit) {
    if (nodo != NULL) {
        itree_recorrer_dfs(nodo->left, visit);
        visit(nodo->interval.a, nodo->interval.b);
        itree_recorrer_dfs(nodo->right, visit);
    }
}

void itree_recorrer_bfs(ITree nodo, FuncionVisitante visit){
    Cola cola = cola_crear();
    ITree temp = nodo;
    while (temp != NULL){
        visit(temp->interval.a, temp->interval.b);
        if (temp->left != NULL)
            cola_encolar(cola, temp->left);
        if(temp->right != NULL)
            cola_encolar(cola, temp->right);
        temp = cola_desencolar(cola);
    }
}
