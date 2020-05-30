#include "itree.h"
#include "cola.h"
#include "stdlib.h"

ITree itree_crear() {
    return NULL;
}

void itree_destruir(ITree nodo) {
    if (nodo != NULL){
        free(nodo->left);
        free(nodo->right);
        free(nodo);
    }
}

void itree_recorrer_dfs(ITree nodo, FuncionVisitante visit) {
    if (nodo != NULL) {
        itree_recorrer_dfs(nodo->left, visit);
        visit(nodo->interval.a, nodo->interval.b);
        itree_recorrer_dfs(nodo->right, visit);
    }
}

void itree_recorrer_bfs(ITree nodo, FuncionVisitante visit){
    Cola cola = cola_crear();
    ITree temp = nodo;
    while (temp != NULL){
        visit(temp->interval.a, temp->interval.b);
        if (temp->left != NULL) {
            cola_encolar(cola, temp->left);
        }
        if(temp->right != NULL) {
            cola_encolar(cola, temp->right);
        }
        temp = cola_desencolar(cola);
    }
}
