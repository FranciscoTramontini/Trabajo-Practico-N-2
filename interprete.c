#include <stdio.h>
#include <string.h>
#include "itree.h"

static void imprimir_intervalo (double dato1, double dato2, int dato3) {
	printf("[%f, %f] |%d| ", dato1, dato2, dato3);
}

int main() {

	ITree raiz = itree_crear();
	Intervalo dato;
	char palabra[100];
	char com[100];
	char interv[100];
	//double a,b;

	while (strcmp(com, "salir") != 0) {
		if (strcmp(com, "i") == 0) {
			itree_insertar(&raiz, dato);
			printf("se inserto ");
			//imprimir_intervalo(dato.a,dato.b, );
			printf("\n");
		}
		//~ else if (strcmp(com, "e")) {
			//~ itree_eliminar(&raiz, dato);
		//~ }
		//~ else if (strcmp(com, "?")) {
			//~ Intervalo aux = itree_intersectar(&raiz, dato);
			//~ if (aux == NULL)
				//~ puts("No\n");
			//~ else
				//~ printf("Si, [%lf,%lf]", aux.a, aux.b);
		//~ }
		else if (strcmp(com, "dfs")) {
			itree_recorrer_dfs(raiz, imprimir_intervalo);
			puts("");
		}
		else if (strcmp(com, "bfs") == 0) {
			itree_recorrer_bfs(raiz, imprimir_intervalo);
			puts("");
		}
		//scanf("%s[^\n]s\n", palabra);

		//lei que gets no es muy recomendable utilizarlo.
        fgets(palabra, sizeof(palabra), stdin);  //leer string entero
        size_t len = strlen(palabra);
        if (len && (palabra[len-1] == '\n')) { //reemplaza \n con \0
            palabra[len-1] = '\0';
        }
        printf ("palabra: %s\n" ,palabra); //test si llego hasta aca
        sscanf(palabra, "%s %[^\n]s" ,com ,interv); //separa com e intervalo
        printf("com: %s interv: %s\n" ,com ,interv); //test si llego hasta aca
		sscanf(interv,"[%lf,%lf]" ,&dato.a ,&dato.b); //separa doubles del intervalo
		//printf("a: %f b: %f \n",a,b); //test si llego hasta aca
		//sscanf(a, "%lf", &dato.a);
		//sscanf(b, "%lf", &dato.b);
	}
	itree_destruir(raiz);
	return 0;
}
