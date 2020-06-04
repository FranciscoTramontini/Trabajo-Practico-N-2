#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

#define MAX(a,b) ((a) > (b) ? a : b)
/* Determina si un valor es mayor que otro o viceversa */

int avl_altura(ITree nodo) {
	if (nodo == NULL)
		return 0;
	else
		return nodo->altura;
}

int avl_calcular_altura(ITree nodo) {
	if (nodo == NULL)
		return 0;
	else
		return MAX(avl_altura(nodo->left), avl_altura(nodo->right)) + 1;
}

double avl_calcular_max(ITree nodo) {
	if (nodo->left == NULL){
		if (nodo->right != NULL)
			return MAX(nodo->right->extra,nodo->extra);
			/* caso extremos izquierdos iguales, sin hijo izquierdo
			 * con hijo derecho */
		else
			return nodo->extra;
			/* caso sin hijos*/
	}
	else if (nodo->left != NULL && nodo->right == NULL)
		return MAX(nodo->left->extra,nodo->extra);
		/* caso solo hijo izquierdo */
	else
		return MAX(nodo->extra,MAX(nodo->left->extra,nodo->right->extra));
		/* caso con dos hijos */
}

int avl_balance_factor(ITree nodo) {
	return avl_altura(nodo->right) - avl_altura(nodo->left);
}

void avl_rotacion_simple_derecha(ITree *nodo) {
	ITNodo *aux;

	aux = (*nodo)->left;
	(*nodo)->left = aux->right;
	aux->right = (*nodo);
	/* rotacion */
	(*nodo)->altura = avl_calcular_altura((*nodo));
	aux->altura = avl_calcular_altura(aux);
	/* calculo de alturas para los nodos intercambiados */

	(*nodo)->extra = avl_calcular_max((*nodo));
	aux->extra = avl_calcular_max(aux);
	/* calculo del maximo valor del intervalo en los nodos cambiados */

	(*nodo) = aux;
}

void avl_rotacion_simple_izquierda(ITree *nodo) {
	ITNodo *aux;

	aux = (*nodo)->right;
	(*nodo)->right = aux->left;
	aux->left = (*nodo);
	/* rotacion */

	(*nodo)->altura = avl_calcular_altura((*nodo));
	aux->altura = avl_calcular_altura(aux);
	/* calculo de alturas para los nodos intercambiados */

	(*nodo)->extra = avl_calcular_max((*nodo));
	aux->extra = avl_calcular_max(aux);
	/* calculo del maximo valor del intervalo en los nodos cambiados */

	(*nodo) = aux;
}

void avl_rotacion_doble_izquierda_derecha(ITree *nodo) {
	avl_rotacion_simple_izquierda(&((*nodo)->left));

	avl_rotacion_simple_derecha(nodo);
}

void avl_rotacion_doble_derecha_izquierda(ITree *nodo) {
	avl_rotacion_simple_derecha(&((*nodo)->right));

	avl_rotacion_simple_izquierda(nodo);
}

void avl_balancear(ITree *nodo, Intervalo dato) {
	if ((*nodo) == NULL) return;

	if (dato.a > (*nodo)->interval.a)
		avl_balancear(&((*nodo)->right), dato);
	else if (dato.a < (*nodo)->interval.a)
		avl_balancear(&((*nodo)->left), dato);

	switch (avl_balance_factor((*nodo))) {
		case 2:
		if (avl_altura((*nodo)->right->right) > avl_altura((*nodo)->right->left))
			avl_rotacion_simple_izquierda(nodo);
		else
			avl_rotacion_doble_derecha_izquierda(nodo);
		break;
		case -2:
		if (avl_altura((*nodo)->left->left) > avl_altura((*nodo)->left->right))
			avl_rotacion_simple_derecha(nodo);
		else
			avl_rotacion_doble_izquierda_derecha(nodo);
		break;
	}
}
