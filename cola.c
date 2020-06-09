#include "cola.h"
#include <stdlib.h>
#include <assert.h>

Cola cola_crear() {
	Cola nuevaCola = malloc(sizeof(struct _Cola));
	assert(nuevaCola);
  	nuevaCola->primero = NULL;
  	nuevaCola->ultimo = NULL;
  	return nuevaCola;
}

ITree cola_primero(Cola cola) {
	return cola->primero->dato;
}

void cola_encolar(Cola cola, ITree dato) {
	SNodo *nuevoNodo = malloc(sizeof(SNodo));
	assert(nuevoNodo);
	nuevoNodo->dato = dato;
	nuevoNodo->sig = NULL;

	if(cola->primero == NULL){
		cola->primero = nuevoNodo;
		cola->ultimo = nuevoNodo;
		return;
	}

	SNodo *nodo = cola->primero;
	for(;nodo->sig != NULL; nodo = nodo->sig);
	/* nodo apunta al ultimo elemento de la cola. */

	nodo->sig = nuevoNodo;
	cola->ultimo = nuevoNodo;
}

ITree cola_desencolar(Cola cola){
	if (cola->primero == NULL) return NULL;

	SNodo* aux = cola->primero;
	cola->primero = aux->sig;
	ITree temp = aux->dato;
	free(aux);
	return temp;
}

void cola_destruir(Cola cola) {
	SNodo *nodoAEliminar;

	while (cola->primero != NULL) {
		nodoAEliminar = cola->primero;
		cola->primero = cola->primero->sig;
		free(nodoAEliminar);
	}
	free(cola);
}
