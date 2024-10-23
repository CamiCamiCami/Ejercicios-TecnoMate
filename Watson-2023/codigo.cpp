#include <stdlib.h>

struct __nodo {
    int id;
    struct __nodo* izq;
    struct __nodo* der;
};

typedef struct __nodo* Arbol;

Arbol deLista(int lista[], int largo) {
    if (largo == 0) {
        return NULL;
    }

    Arbol nuevo = (Arbol) malloc(sizeof(struct __nodo));
    int pos = (int)((largo - 1.0) / 2.0);
    nuevo->id = lista[pos];
    nuevo->izq = deLista(lista, )
    
}