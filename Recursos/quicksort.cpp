#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>

int profundidad = 0;
void quicksort(int* lista, int largo) {
    if (largo < 2) {
        return;
    }

    int numero = lista[0];

    int m_largo = 0, M_largo = 0;
    int* aux_mayores = (int*) malloc(sizeof(int) * largo);

    for (int i = 1; i < largo; i++) {
        if (lista[i] < numero) {
            lista[m_largo] = lista[i];
            m_largo++;
        } else {
            aux_mayores[M_largo] = lista[i];
            M_largo++;
        }
    }

    lista[m_largo] = numero;

    for (int i = 0; i < M_largo; i++) {
        lista[m_largo + 1 + i] = aux_mayores[i]; 
    }

    free(aux_mayores);

    quicksort(lista, m_largo);
    quicksort((lista + m_largo + 1), M_largo);
}

int main(void) {
    int lista[30];
    for (int i = 0; i < 30; i++) {
        lista[i] = rand() % 101;
    }

    for(int i = 0; i < 30; i++) {
        printf("%i ", lista[i]);
    }

    printf("\n");

    quicksort(lista, 30);

    for(int i = 0; i < 30; i++) {
        printf("%i ", lista[i]);
    }

    printf("\n");
}