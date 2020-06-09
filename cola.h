#ifndef __COLA_H__
#define __COLA_H__

#include "itree.h"

typedef struct _SNodo {
  ITree dato;
  struct _SNodo *sig;
} SNodo;
/* estructura para un nodo de la cola */

typedef struct _Cola {
	SNodo* primero;
	SNodo* ultimo;
} *Cola;
/* estructura para la cola */

/**
    * cola_crear : void -> Cola
    * Crea una cola vacia.
    */
Cola cola_crear();

/**
    * cola_encolar : Cola -> ITree -> void
    * Agrega un arbol de intervalos al final de la cola pasada como argumento.
    */
void cola_encolar(Cola cola, ITree dato);

/**
    * cola_desencolar : Cola -> ITree
    * Devuelve el primer elemento de la cola pasada como argumento y luego lo
    * elimina.
    */
ITree cola_desencolar(Cola cola);

/**
    * cola_destruir : Cola -> void
    * Libera la memoria pedida de la cola pasada por argumento.
    */
void cola_destruir(Cola cola);

#endif
