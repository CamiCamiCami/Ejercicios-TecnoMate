#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

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

int main(void) {
    int largo = 1000;
    int matriz[10000];
    for (int i = 0; i < largo; i++) {
        matriz[i] = rand() % 100;
    }

    int largoo;
    int* ord = quicksort_set(matriz, largo, &largoo);

    for (int i = 0; i < largoo; i++) {
        printf("%i\n", ord[i]);
    }
}