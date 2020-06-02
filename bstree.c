#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>

int bstree_altura(ITree nodo) {
	if (nodo == NULL) return 0;
	int total = 1;
	int der, izq;
	izq = bstree_altura(nodo->right);
	der = bstree_altura(nodo->left);
	total += (der > izq)?der:izq;
	return total;
}

int bstree_balance_factor(ITree nodo) {
	return bstree_altura(nodo->right) - bstree_altura(nodo->left);
}

void bstree_simple_derecha(ITree *nodo) {
	ITNodo *aux;
	aux = (*nodo)->left;
	(*nodo)->left = aux->right;
	aux->right = (*nodo);
	(*nodo) = aux;
}

void bstree_simple_izquierda(ITree *nodo) {
	ITNodo *aux;
	aux = (*nodo)->right;
	(*nodo)->right = aux->left;
	aux->left = (*nodo);
	(*nodo) = aux;
}

void bstree_doble_izquierda_derecha(ITree *nodo) {
	bstree_simple_izquierda(&((*nodo)->left));
	bstree_simple_derecha(nodo);
}

void bstree_doble_derecha_izquierda(ITree *nodo) {
	bstree_simple_derecha(&((*nodo)->right));
	bstree_simple_izquierda(nodo);
}

void bstree_balancear(ITree *nodo, Intervalo dato) {
	if ((*nodo) == NULL) return;
	if (dato.a > (*nodo)->interval.a)
		bstree_balancear(&((*nodo)->right), dato);
	else if (dato.a < (*nodo)->interval.a)
		bstree_balancear(&((*nodo)->left), dato);
	switch (bstree_balance_factor((*nodo))) {
		case 2:
		if (bstree_altura((*nodo)->right->right) >
									        bstree_altura((*nodo)->right->left))
			bstree_simple_izquierda(nodo);
		else
			bstree_doble_derecha_izquierda(nodo);
		break;
		case -2:
		if (bstree_altura((*nodo)->left->left) >
									        bstree_altura((*nodo)->left->right))
			bstree_simple_derecha(nodo);
		else
			bstree_doble_izquierda_derecha(nodo);
		break;
	}
}
