#include <stdio.h>
#include <stdlib.h>

char* quicksort(char* lista, int largo) {
    if (largo < 1) {
        return NULL;
    }
    char* menores = (char*)malloc(sizeof(char) * largo);
    char* mayores = (char*)malloc(sizeof(char) * largo);
    int largo_menores = 0;
    int largo_mayores = 0;
    char caracter = lista[0];
    for (int i = 1; i < largo; i++) {
        if (lista[i] < caracter) {
            menores[largo_menores++] = lista[i];
        } else {
            mayores[largo_mayores++] = lista[i]; 
        }
    }

    char* menores_ord = quicksort(menores, largo_menores);
    char* mayores_ord = quicksort(mayores, largo_mayores);

    free(menores);
    free(mayores);

    char* ordenada = (char*)malloc(sizeof(char) * largo);

    for (int i = 0; i < largo_menores; i++) {
        ordenada[i] = menores_ord[i];
    }
    ordenada[largo_menores] = caracter;
    for (int i = 0; i < largo_mayores; i++) {
        ordenada[largo_menores + 1 + i] = mayores_ord[i];
    }

    free(menores_ord);
    free(mayores_ord);

    return ordenada;
}


char* antiquicksort(char* lista, int largo) {
    if (largo < 1) {
        return NULL;
    }
    char* menores = (char*)malloc(sizeof(char) * largo);
    char* mayores = (char*)malloc(sizeof(char) * largo);
    int largo_menores = 0;
    int largo_mayores = 0;
    char caracter = lista[0];
    for (int i = 1; i < largo; i++) {
        if (lista[i] < caracter) {
            menores[largo_menores++] = lista[i];
        } else {
            mayores[largo_mayores++] = lista[i]; 
        }
    }

    char* menores_ord = antiquicksort(menores, largo_menores);
    char* mayores_ord = antiquicksort(mayores, largo_mayores);

    free(menores);
    free(mayores);

    char* ordenada = (char*)malloc(sizeof(char) * largo);

    for (int i = 0; i < largo_mayores; i++) {
        ordenada[i] = mayores_ord[i];
    }
    ordenada[largo_mayores] = caracter;
    for (int i = 0; i < largo_menores; i++) {
        ordenada[largo_mayores + 1 + i] = menores_ord[i];
    }

    free(menores_ord);
    free(mayores_ord);

    return ordenada;
}

int mayor(int n) {
    char str[5];
    sprintf(str, "%04d", n);
    char* mayor_str = antiquicksort(str, 4);
    int mayor;
    sscanf(mayor_str, "%04d", &mayor);
    free(mayor_str);
    return mayor;
}

int menor(int n) {
    char str[5];
    sprintf(str, "%04d", n);
    char* menor_str = quicksort(str, 4);
    int menor;
    sscanf(menor_str, "%04d", &menor);
    free(menor_str);
    return menor;
}

int kaprekar(int n, int test, int vida, bool primero) {
    if (n == test && !primero) {
        //printf("%i: AntiKaprekiano\n", n);
        return -1;
    } 

    if (vida < 0) {
        test = n;
        vida = 10;
    } else {
        vida--;
    }

    if (n == 6174) {
        //printf("%i: Kaprekar\n", n);
        return 0;
    } else {
        int men = menor(n);
        int may = mayor(n);
        int nuevo = mayor(n) - menor(n);
        //printf("%i: %i - %i = %i\n", n, may, men, nuevo);
        int resultado = kaprekar(nuevo, test, vida, false);
        return resultado == -1 ? -1 : resultado + 1;
    }
}

int main(void) {
    int largo;
    scanf("%i", &largo);

    for (int i = 0; i < largo; i++) {
        int n;
        scanf("%i", &n);
        printf("Caso #%i: %i\n", i+1, kaprekar(n, n, 10, true));
    }
}