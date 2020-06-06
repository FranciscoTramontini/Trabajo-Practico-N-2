#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

Cola cola_crear() {
	Cola nuevaCola = malloc(sizeof(struct _Cola));
  	nuevaCola->primero = NULL;
  	nuevaCola->ultimo = NULL;
  	return nuevaCola;
}

void cola_encolar(Cola cola, ITree dato) {
	SNodo *nuevoNodo = malloc(sizeof(SNodo));
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
	return aux->dato;
}

void slist_destruir(Cola cola) {
	SNodo *nodoAEliminar;
	while (cola->primero != NULL) {
		nodoAEliminar = cola->primero;
		cola->primero = cola->primero->sig;
		free(nodoAEliminar);
	}
}
