#ifndef __ITREE_H__
#define __ITREE_H__

typedef void (*FuncionVisitante) (double dato1, double dato2, double dato3, int dato4);
/* función puntero. */

typedef struct _Intervalo {
    double a, b;
} Intervalo;

typedef struct _ITNodo {
    Intervalo interval;
    double extra;
    struct _ITNodo *left;
    struct _ITNodo *right;
    int altura;
} ITNodo;
/* estructura de un nodo del arbol de intervalos */
typedef ITNodo *ITree;
/* arbol de intervalos */

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
    * itree_insertar : *ITree -> Intervalo -> void
    * Dado la direccion donde apunta el arbol pasado como argumento, insertamos
    * el intervalo pasado como argumento. Siempre respetando que sea un arbol de
    * intervalos AVL.
    */
void itree_insertar(ITree *nodo, Intervalo dato);

/**
    * itree_eliminar : *ITree -> Intervalo -> void
    * Dado la direccion donde apunta el arbol de intervalos pasado como
    * argumento eliminamos, si es que se encuentra en el arbol, el intervalo
    * pasado como argumento. Siempre respetando que sea un arbol de intervalos
    * AVL.
    */
void itree_eliminar(ITree *nodo, Intervalo dato);

/**
    * itree_intersectar : *ITree -> Intervalo -> *ITNodo
    * Busca un intervalo en el arbol que intersecte con el intervalo dado como
    * argumento, haciendo comparaciones entre los extremos del nodo con el
    * intervalo dado y haciendo uso del dato extra del maximo extremo derecho
    * para determinar si es posible dicha interseccion. Retorna el nodo que lo
    * intersecte
    */
ITNodo* itree_intersectar(ITree *nodo, Intervalo dato);

/**
    * itree_recorrer_dfs : ITree -> FuncionVisitante -> viod
    * Recorre el arbol pasado como argumento con el metodo primero por
    * profundidad con recorrido inorden, utilizando la funcion pasada.
    */
void itree_recorrer_dfs(ITree nodo, FuncionVisitante visit);

/**
    * itree_recorrer_bfs : ITree -> FuncionVisitante -> void
    * Recorre el arbol pasado como argumento con el metodo primero a lo ancho
    * utilizando colas y la funcion pasada.
    */
void itree_recorrer_bfs(ITree nodo, FuncionVisitante visit);

#endif /* __ITREE_H__ */
