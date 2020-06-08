#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

// Ver si se puede hacer esto.
#define MAX(a,b) ((a) > (b) ? a : b)
/* Determina si un elemento es mayor que otro o viceversa */

int avl_altura(ITree nodo) {
	if (nodo == NULL)
		return 0;
	else
		return nodo->altura;
}
// Funcion calcular altura que no devuelve nada, hace todo interno.

void avl_actualizar_altura(ITree nodo) {
	if (nodo != NULL)
		nodo->altura = MAX(avl_altura(nodo->left), avl_altura(nodo->right)) + 1;
}
// int avl_calcular_altura(ITree nodo) {
// 	if (nodo == NULL)
// 		return 0;
// 	else
// 		return MAX(avl_altura(nodo->left), avl_altura(nodo->right)) + 1;
// }

// Igual que calcular altura, podemos hacerlo que haga todo interno en la funcion.
void avl_actualizar_max(ITree nodo) {
	if (nodo != NULL){
		if (nodo->left == NULL) {
			if (nodo->right != NULL)
				nodo->extra = MAX(nodo->right->extra,nodo->interval.b);
			/* caso extremos izquierdos iguales, sin hijo izquierdo
			 * con hijo derecho */
			else
				nodo->extra = nodo->interval.b;
			/* caso sin hijos */
		}
		else if (nodo->left != NULL && nodo->right == NULL)
			nodo->extra = MAX(nodo->left->extra,nodo->interval.b);
		/* caso solo hijo izquierdo */
		else
			nodo->extra = MAX(nodo->interval.b,MAX(nodo->left->extra,nodo->right->extra));
		}
}
// double avl_calcular_max(ITree nodo) {
// 	if (nodo->left == NULL){
// 		if (nodo->right != NULL)
// 			return MAX(nodo->right->extra,nodo->extra);
// 			/* caso extremos izquierdos iguales, sin hijo izquierdo
// 			 * con hijo derecho */
// 		else
// 			return nodo->extra;
// 			/* caso sin hijos*/
// 	}
// 	else if (nodo->left != NULL && nodo->right == NULL)
// 		return MAX(nodo->left->extra,nodo->extra);
// 		/* caso solo hijo izquierdo */
// 	else
// 		return MAX(nodo->extra,MAX(nodo->left->extra,nodo->right->extra));
// 		/* caso con dos hijos */
// }

int avl_balance_factor(ITree nodo) {
	return avl_altura(nodo->right) - avl_altura(nodo->left);
}

void avl_rotacion_simple_derecha(ITree *nodo) {
	ITNodo *aux;

	aux = (*nodo)->right;
	(*nodo)->right = aux->left;
	aux->left = (*nodo);
	/* rotacion */

	avl_actualizar_altura((*nodo));
	avl_actualizar_altura(aux);
	/* calculo de alturas para los nodos intercambiados */

	avl_actualizar_max((*nodo));
	avl_actualizar_max(aux);
	/* calculo del maximo valor del intervalo en los nodos cambiados */

	(*nodo) = aux;
}
// void avl_rotacion_simple_derecha(ITree *nodo) {
// 	ITNodo *aux;
//
// 	aux = (*nodo)->left;
// 	(*nodo)->left = aux->right;
// 	aux->right = (*nodo);
// 	/* rotacion */
//
// 	//avl_calcular_altura((*nodo));
// 	//avl_calcular_altura(aux);
// 	(*nodo)->altura = avl_calcular_altura((*nodo));
// 	aux->altura = avl_calcular_altura(aux);
// 	/* calculo de alturas para los nodos intercambiados */
//
// 	//avl_calcular_max((*nodo));
// 	//avl_calcular_max(aux);
// 	(*nodo)->extra = avl_calcular_max((*nodo));
// 	aux->extra = avl_calcular_max(aux);
// 	/* calculo del maximo valor del intervalo en los nodos cambiados */
//
// 	(*nodo) = aux;
// }

void avl_rotacion_simple_izquierda(ITree *nodo) {
	ITNodo *aux;

	aux = (*nodo)->left;
	(*nodo)->left = aux->right;
	aux->right = (*nodo);
	/* rotacion */

	avl_actualizar_altura((*nodo));
	avl_actualizar_altura(aux);
	/* calculo de alturas para los nodos intercambiados */

	avl_actualizar_max((*nodo));
	avl_actualizar_max(aux);
	/* calculo del maximo valor del intervalo en los nodos cambiados */

	(*nodo) = aux;
}
// void avl_rotacion_simple_izquierda(ITree *nodo) {
// 	ITNodo *aux;
//
// 	aux = (*nodo)->right;
// 	(*nodo)->right = aux->left;
// 	aux->left = (*nodo);
// 	/* rotacion */
//
// 	//avl_calcular_altura((*nodo));
// 	//avl_calcular_altura(aux);
// 	(*nodo)->altura = avl_calcular_altura((*nodo));
// 	aux->altura = avl_calcular_altura(aux);
// 	/* calculo de alturas para los nodos intercambiados */
//
// 	//avl_calcular_max((*nodo));
// 	//avl_calcular_max(aux);
// 	(*nodo)->extra = avl_calcular_max((*nodo));
// 	aux->extra = avl_calcular_max(aux);
// 	/* calculo del maximo valor del intervalo en los nodos cambiados */
//
// 	(*nodo) = aux;
// }

void avl_rotacion_doble_izquierda(ITree *nodo) {
	avl_rotacion_simple_derecha(&((*nodo)->left));
	avl_rotacion_simple_izquierda(nodo);
}
// void avl_rotacion_doble_izquierda_derecha(ITree *nodo) {
// 	avl_rotacion_simple_izquierda(&((*nodo)->left));
//
// 	avl_rotacion_simple_derecha(nodo);
// }

void avl_rotacion_doble_derecha(ITree *nodo) {
	avl_rotacion_simple_izquierda(&((*nodo)->right));
	avl_rotacion_simple_derecha(nodo);
}
// void avl_rotacion_doble_derecha_izquierda(ITree *nodo) {
// 	avl_rotacion_simple_derecha(&((*nodo)->right));
// 	avl_rotacion_simple_izquierda(nodo);
// }

void avl_balancear(ITree *nodo) {
	if ((*nodo) != NULL) {
		switch (avl_balance_factor((*nodo))) {
			case 2:
			if (avl_altura((*nodo)->right->right) > avl_altura((*nodo)->right->left))
				avl_rotacion_simple_derecha(nodo);
			else
				avl_rotacion_doble_derecha(nodo);
			break;
			case -2:
			if (avl_altura((*nodo)->left->left) > avl_altura((*nodo)->left->right))
				avl_rotacion_simple_izquierda(nodo);
			else
				avl_rotacion_doble_izquierda(nodo);
			break;
		}
	}
}
// void avl_balancear(ITree *nodo, Intervalo dato) {
// 	if ((*nodo) == NULL) return;
//
// 	if (dato.a > (*nodo)->interval.a)
// 		avl_balancear(&((*nodo)->right), dato);
// 	else if (dato.a < (*nodo)->interval.a)
// 		avl_balancear(&((*nodo)->left), dato);
//
// 	switch (avl_balance_factor((*nodo))) {
// 		case 2:
// 		if (avl_altura((*nodo)->right->right) > avl_altura((*nodo)->right->left))
// 			avl_rotacion_simple_izquierda(nodo);
// 		else
// 			avl_rotacion_doble_derecha_izquierda(nodo);
// 		break;
// 		case -2:
// 		if (avl_altura((*nodo)->left->left) > avl_altura((*nodo)->left->right))
// 			avl_rotacion_simple_derecha(nodo);
// 		else
// 			avl_rotacion_doble_izquierda_derecha(nodo);
// 		break;
// 	}
// }
