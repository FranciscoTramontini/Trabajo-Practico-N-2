#ifndef __COLA_H__
#define __COLA_H__

#include <stddef.h>
#include "itree.h"

typedef struct _SNodo {
  ITree dato;
  struct _SNodo *sig;
} SNodo;

typedef struct _Cola {
	SNodo* primero;
	SNodo* ultimo;
} *Cola;

/**
 * Crea una cola vacia.
*/
Cola cola_crear ();

/**
 * Agrega el elemento al final de la cola.
*/
void cola_encolar(Cola cola, ITree dato);

/**
 * Elimina el primer elemento de la cola.
*/
ITree cola_desencolar(Cola cola);

/**
 * Destruye una pila.
*/
void cola_destruir (Cola cola);

#endif
