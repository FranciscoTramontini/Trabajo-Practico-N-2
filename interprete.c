#include <stdio.h>
#include <string.h>
#include "itree.h"

static void imprimir_intervalo (double dato1, double dato2) {
	printf("[%f, %f]", dato1, dato2);
}

int main() {
	
	ITree raiz = itree_crear();
	Intervalo interval;
	char palabra[] = "";
	
	while (strcmp(palabra, "salir") != 0) {
		scanf("%s [%lf, %lf]", palabra, &interval.a, &interval.b);
		if (strcmp(palabra, "i") == 0) {
			itree_insertar(raiz, interval);
		}
		else if (strcmp(palabra, "e") == 0) {
			itree_eliminar(raiz, interval);
		}
		else if (strcmp(palabra, "dfs") == 0) {
			itree_recorrer_dfs(raiz, imprimir_intervalo);
		}
	}
	itree_destruir(raiz);
	return 0;
}

