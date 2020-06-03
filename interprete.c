#include <stdio.h>
#include <string.h>
#include "itree.h"

static void imprimir_intervalo (double dato1, double dato2) {
	printf("[%f, %f]", dato1, dato2);
}

int main() {

	ITree raiz = itree_crear();
	Intervalo dato;
	char palabra[] = {};
	char a[] = {};
	char b[] = {};

	while (strcmp(palabra, "salir") != 0) {
		if (strcmp(palabra, "i") == 0) {
			itree_insertar(&raiz, dato);
		}
		if (strcmp(palabra, "bfs") == 0) {
			itree_recorrer_bfs(raiz, imprimir_intervalo);
			puts("");
		}
		scanf("%s[^\n]s\n", palabra);
		sscanf(palabra, "%s [%s, %s]", palabra, a, b);
		sscanf(a, "%lf", &dato.a);
		sscanf(b, "%lf", &dato.b);
	}
	itree_destruir(raiz);
	return 0;
}
