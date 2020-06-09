#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itree.h"

/**
	* imprimir_intervalo : double -> double -> void
	* Imprime un intervalo de la forma [double, double].
	*/
static void imprimir_intervalo (double dato1, double dato2, double dato3, int dato4) {
	printf(" [%.2f, %.2f] m:|%.2f| h:|%d| ", dato1, dato2, dato3, dato4);
}

// Falta verificar que a <= b
int main() {
	ITree raiz = itree_crear();
	Intervalo dato;
	// for (int i = 1; i < 20; i++) {
	// 	Intervalo test;
	// 	test.a = i;
	// 	test.b = i+1;
	// 	itree_insertar(&raiz, test);
	// }
	// Intervalo dato;
	// dato.a = 5;
	// dato.b = 6;
	// itree_eliminar(&raiz, dato);
	//
	// Intervalo dato2;
	// dato2.a = 1;
	// dato2.b = 2;
	// itree_eliminar(&raiz, dato2);
	//
	// itree_recorrer_bfs(raiz, imprimir_intervalo);
	// itree_recorrer_dfs(raiz, imprimir_intervalo);


	char palabra[100] = {};
	char com[100] = {};
	char interv[100] = {};

	while (strcmp(com, "salir") != 0) {
		if (strcmp(com, "i") == 0) {
			sscanf(interv,"[%lf,%lf]" ,&dato.a ,&dato.b);
			itree_insertar(&raiz, dato);
		}
		else if (strcmp(com, "e") == 0) {
			sscanf(interv,"[%lf,%lf]" ,&dato.a ,&dato.b);
			itree_eliminar(&raiz, dato);
		}
		else if (strcmp(com, "?") == 0) {
			sscanf(interv,"[%lf,%lf]" ,&dato.a ,&dato.b);
			ITNodo *aux = itree_intersectar(&raiz, dato);
			if (aux == NULL)
				puts(" No");
			else{
                Intervalo I;
                I.a = aux->interval.a;
                I.b = aux->interval.b;
				printf(" Si, [%.2f,%.2f] \n", I.a, I.b);
			}
		}
		else if (strcmp(com, "dfs") == 0) {
			itree_recorrer_dfs(raiz, imprimir_intervalo);
			puts("");
		}
		else if (strcmp(com, "bfs") == 0) {
			itree_recorrer_bfs(raiz, imprimir_intervalo);
			puts("");
		}
		//lei que gets no es muy recomendable utilizarlo.
        fgets(palabra, sizeof(palabra), stdin);
 		/* lee la palabra ingresada*/
        size_t len = strlen(palabra);
        if (len && (palabra[len-1] == '\n')) { //reemplaza \n con \0
            palabra[len-1] = '\0';
		/* Remplazamos '\n'por un '\0' para crear un string*/
        }
        sscanf(palabra, "%s %[^\n]s" ,com ,interv);
 		/* separa la palabra en identificador e intervalo */
		// sscanf(interv,"[%lf,%lf]" ,&dato.a ,&dato.b);
		/* separa el intervalo */
	}
	itree_destruir(raiz);
	return 0;
}
