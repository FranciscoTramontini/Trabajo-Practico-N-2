#ifndef __AVL_H__
#define __AVL_H__

#include "itree.h"
/**
 * Devuelve la altura del nodo.
 */
int avl_altura(ITree nodo);
/**
 * Calcula la altura de un nodo, altura = max(nodo.left,nodo.right)+1
 */
int avl_calcularaltura(ITree nodo);
/**
 * Calcula el maximo local, comparando los maximos de los hijos y del nodo
 */
double avl_calcularmax(ITree nodo);

/**
 * Devuelve la diferencia de altura de sus dos arboles hijos.
 */
int avl_balance_factor(ITree nodo);

/**
 * Hace una rotacion simple a la derecha al arbol.
 */
void avl_rotacion_simple_derecha(ITree *nodo);

/**
 * Hace una rotacion simple a la izquierda al arbol.
 */
void avl_rotacion_simple_izquierda(ITree *nodo);

/**
 * Hace una rotacion doble de la izquierda a la derecha del arbol.
 */
void avl_rotacion_doble_izquierda_derecha(ITree *nodo);

/**
 * Hace una rotacion doble de la derecha a la izquierda del arbol.
 */
void avl_rotacion_doble_derecha_izquierda(ITree *nodo);

/**
 * Balanceamos un arbol.
 */
void avl_balancear(ITree *nodo, Intervalo dato);

void bstree_maximo(ITree nodo);
#endif /* __AVL_H__ */
