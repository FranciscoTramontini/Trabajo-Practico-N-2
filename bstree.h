#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "itree.h"
/**
 * Devuelve la altura del arbol.
 */
int bstree_altura(ITree nodo);

/**
 * Devuelve la diferencia de altura de sus dos arboles hijos.
 */
int bstree_balance_factor(ITree nodo);

/**
 * Hace una rotacion simple a la derecha al arbol.
 */
void bstree_simple_derecha(ITree *nodo);

/**
 * Hace una rotacion simple a la izquierda al arbol.
 */
void bstree_simple_izquierda(ITree *nodo);

/**
 * Hace una rotacion doble de la izquierda a la derecha del arbol.
 */
void bstree_doble_izquierda_derecha(ITree *nodo);

/**
 * Hace una rotacion doble de la derecha a la izquierda del arbol.
 */
void bstree_doble_derecha_izquierda(ITree *nodo);

/**
 * Balanceamos un arbol.
 */
void bstree_balancear(ITree *nodo, Intervalo dato);

void bstree_maximo(ITree nodo);
#endif /* __BSTREE_H__ */
