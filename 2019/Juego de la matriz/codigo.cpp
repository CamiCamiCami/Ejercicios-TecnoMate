#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int* quicksort(int* lista, int largo) {
    if (largo < 1) {
        return NULL;
    }

    int largo_menores = 0;
    int largo_mayores = 0;
    int numero = lista[0];
    int* menores = (int*)malloc(sizeof(int) * largo);
    int* mayores = (int*)malloc(sizeof(int) * largo);

    for (int i = 1; i < largo; i++) {
        if (lista[i] < numero) {
            menores[largo_menores++] = lista[i];
        } else {
            mayores[largo_mayores++] = lista[i];
        }
    }

    int* menoresord = quicksort(menores, largo_menores);
    int* mayoresord = quicksort(mayores, largo_mayores);

    int* ordenada = (int*)malloc(sizeof(int) * largo);

    for (int i = 0; i < largo_menores; i++) {
        ordenada[i] = menoresord[i];
    }
    ordenada[largo_menores] = numero;
    for (int i = 0; i < largo_mayores; i++) {
        ordenada[largo_menores + 1 + i] = mayoresord[i];
    }

    free(menores);
    free(mayores);

    if (largo_menores) free(menoresord);
    if (largo_mayores) free(mayoresord);

    return ordenada;
}


int frecuenciaEnMatriz(int matriz[], int largo, int num) {
    int cont = 0;
    for (int i = 0; i < largo; i++) {
        if (matriz[i] == num) {
            cont++;
        }
    }
    return cont;
}

int main(void) {
    int largo, queries;
    scanf("%i %i", &largo, &queries);
    int matriz[largo];

    for (int i = 0; i < largo; i++) {
        scanf("%i ", &matriz[i]);
    }

    for (int i = 0; i < queries; i++) {
        int desde, hasta, k, gugu, dabriel;
        scanf("%i %i %i %i %i", &desde, &hasta, &k, &gugu, &dabriel);
        int* submatriz = matriz + desde - 1;
        int submatriz_largo = hasta - desde + 1;
        int elementos_distintos;
        int* submatriz_ord = quicksort(submatriz, submatriz_largo);
        int buscar = submatriz_ord[k-1];
        free(submatriz_ord);
        int res = frecuenciaEnMatriz(submatriz, submatriz_largo, buscar);
        gugu -= res;
        dabriel -= res;
        gugu = gugu < 0 ? -gugu : gugu;
        dabriel = dabriel < 0 ? -dabriel : dabriel;
        if (gugu < dabriel) {
            printf("%i %i G\n", buscar, res);
        } else if (gugu > dabriel) {
            printf("%i %i D\n", buscar, res);
        } else {
            printf("%i %i E\n", buscar, res);
        }
    }
}