#ifndef __ITREE_H__
#define __ITREE_H__

typedef void (*FuncionVisitante) (double dato1, double dato2);
/* Funcion puntero. */

typedef struct _Intervalo {
    double a, b;
} Intervalo;

typedef struct _ITNodo {
    Intervalo interval;
    double extra;
    struct _ITNodo *left;
    struct _ITNodo *right;
} ITNodo;

typedef ITNodo *ITree;

/**
    * itree_crear : void -> Itree
    * Crea un arbol de intervalos vacio.
  */
ITree itree_crear();

/**
    * itree_destruir : ITree -> void
    * Dado un arbol, libera la memoria pedida.
    */
void itree_destruir(ITree nodo);

/**
    * itree_recorrer_dfs : ITree -> FuncionVisitante -> viod
    * Recorre el arbol pasado como argumento con el metodo primero por
    * profundidad, utilizando la funcion pasada.
  */
void itree_recorrer_dfs(ITree nodo, FuncionVisitante visit);

/**
    * itree_recorrer_bfs : ITree -> FuncionVisitante -> void
    * Recorre el arbol pasado como argumento con el metodo primero a lo ancho
    * utilizando la funcion pasada.
    */
void itree_recorrer_bfs(ITree nodo, FuncionVisitante visit);

#endif /* __ITREE_H__ */
