#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>

// In place
// O(n logn)
void quicksort(int* lista, int largo) {
    if (largo < 2) {
        return;
    }

    int largo_menores = 0;
    int largo_mayores = 0;
    int numero = lista[0];
    int numVolando = lista[1];
    bool ultMenor = true;
    for (int i = 1; i < largo; i++) {
        int aux = numVolando;
        if (ultMenor) {
            if(numVolando < numero) {
                numVolando = lista[largo_menores + 2];
                lista[largo_menores++] = aux;
            } else {
                numVolando = lista[largo - 1 - largo_mayores];
                lista[largo - 1 - largo_mayores++] = aux;
                ultMenor = false;
            }
        } else {
            if(numVolando < numero) {
                numVolando = lista[largo_menores + 2];
                lista[largo_menores++] = aux;
                ultMenor = true;
            } else {
                numVolando = lista[largo - 1 - largo_mayores];
                lista[largo - 1 - largo_mayores++] = aux;
            }
        }
    }

    lista[largo_menores] = numero;

    quicksort(lista, largo_menores);
    quicksort((lista + largo_menores + 1), largo_mayores);
}

int* quicksort_set(int* lista, int largo, int* nuevo_largo) {
    if (largo < 1) {
        *nuevo_largo = 0;
        return NULL;
    }

    int largo_menores = 0;
    int largo_mayores = 0;
    int numero = lista[0];
    int* menores = (int*)malloc(sizeof(int) * largo);
    int* mayores = (int*)malloc(sizeof(int) * largo);

    bool ultMenor = true;
    for (int i = 1; i < largo; i++) {
        if (lista[i] < numero) {
            menores[largo_menores++] = lista[i];
        } else if (lista[i] > numero) {
            mayores[largo_mayores++] = lista[i];
        }
    }

    int largo_menoresord;
    int* menoresord = quicksort_set(menores, largo_menores, &largo_menoresord);
    int largo_mayoresord;
    int* mayoresord = quicksort_set(mayores, largo_mayores, &largo_mayoresord);

    int* ordenada = (int*)malloc(sizeof(int) * (largo_mayoresord + largo_menoresord + 1));

    for (int i = 0; i < largo_menoresord; i++) {
        ordenada[i] = menoresord[i];
    }
    ordenada[largo_menoresord] = numero;
    for (int i = 0; i < largo_mayoresord; i++) {
        ordenada[largo_menoresord + 1 + i] = mayoresord[i];
    }

    free(menores);
    free(mayores);

    if (largo_menoresord) free(menoresord);
    if (largo_mayoresord) free(mayoresord);

    *nuevo_largo = largo_mayoresord + largo_menoresord + 1;
    return ordenada;
}

/*
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
}*/

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