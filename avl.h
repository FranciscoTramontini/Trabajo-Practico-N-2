#ifndef __AVL_H__
#define __AVL_H__

#include "itree.h"

/**
	* avl_altura : ITree -> int
 	* Devuelve la altura del arbol pasado como argumento.
 	*/
int avl_altura(ITree nodo);

/**
	* avl_calcular_altura : ITree -> int
 	* Calcula la altura de un nodo, altura = max(nodo->left,nodo->right)+1
 	*/
int avl_calcular_altura(ITree nodo);

/**
	* avl_calcular_max : ITree -> double
 	* Calcula el maximo local, comparando los maximos de los hijos y del arbol
	* pasado como argumento.
 	*/
double avl_calcular_max(ITree nodo);

/**
	* avl_balance_factor : ITree -> int
 	* Devuelve la diferencia de altura de sus dos arboles hijos.
 	*/
int avl_balance_factor(ITree nodo);

/**
	* avl_rotacion_simple_derecha : *ITree -> void
 	* Hace una rotacion simple a la derecha al arbol pasado como argumento.
 	*/
void avl_rotacion_simple_derecha(ITree *nodo);

/**
	* avl_rotacion_simple_izquierda : *ITree -> void
 	* Hace una rotacion simple a la izquierda al arbol pasado como argumento.
 	*/
void avl_rotacion_simple_izquierda(ITree *nodo);

/**
	* avl_rotacion_doble_izquierda_derecha : *ITree -> void
 	* Hace una rotacion doble de la izquierda a la derecha del arbol pasado como
	* argumento.
 	*/
void avl_rotacion_doble_izquierda_derecha(ITree *nodo);

/**
	* avl_rotacion_doble_izquierda_derecha : *ITree -> void
 	* Hace una rotacion doble de la derecha a la izquierda del arbol pasado como
	* argumento.
 	*/
void avl_rotacion_doble_derecha_izquierda(ITree *nodo);

/**
	* avl_balancear : *ITree -> Intervalo -> void
 	* Balanceamos en altura el arbol con el intervalo que pasamos como
	* argumentos.
 */
void avl_balancear(ITree *nodo, Intervalo dato);

#endif /* __AVL_H__ */
