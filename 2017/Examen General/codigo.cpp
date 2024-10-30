#include <stdlib.h>
#include <stdio.h>


void quicksort(int* lista, int largo) {
    if (largo < 2) {
        return;
    }
    int* aux_largo = (int*)malloc(sizeof(int) * largo);
    int largo_menores = 0;
    int largo_mayores = 0;
    int numero = lista[0];
    for (int i = 1; i < largo; i++) {
        if (lista[i] < numero) {
            lista[largo_menores++] = lista[i];
        } else {
            aux_largo[largo_mayores++] = lista[i]; 
        }
    }

    lista[largo_menores] = numero;

    for(int i = 0; i < largo_mayores; i++) {
        lista[largo_menores + 1 + i] = aux_largo[i];
    }

    free(aux_largo);

    quicksort(lista, largo_menores);
    quicksort((lista + largo_menores + 1), largo_mayores);
}


int main(void) {
    int largo, queries;
    scanf("%i %i", &largo, &queries);
    int numeros[largo];
    for (int i = 0; i < largo; i ++) {
        scanf("%i", &numeros[i]);
    }

    quicksort(numeros, largo);

    int resultados[queries];

    for (int i = 0; i < queries; i++) {
        int req;
        scanf("%i", &req);
        resultados[i] = numeros[largo - req];
    }

    for (int i = 0; i < queries; i++) {
        printf("%i\n", resultados[i]);
    }
} 