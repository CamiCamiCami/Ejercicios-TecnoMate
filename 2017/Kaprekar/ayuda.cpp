#include <stdio.h>

int main1(void) {
    FILE* f = fopen("ayuda.txt", "w+");
    for (int i = 0; i < 10000; i++) {
        fprintf(f, "%i\n", i);
    }
    fclose(f);
    return 0;
}

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

short previos[10000];
int kaprekar(int n) {
    if (previos[n] == -3) {
        int men = menor(n);
        int may = mayor(n);
        int nuevo = mayor(n) - menor(n);
        previos[n] = -2;
        //printf("%i: %i - %i = %i\n", n, may, men, nuevo);
        int nuevo_res = kaprekar(nuevo);
        previos[n] = nuevo_res == -1 ? -1 : nuevo_res + 1;
        return previos[n];
    } else if (previos[n] == -2) {
        previos[n] = -1;
        return -1;
    } else {
        return previos[n];
    }
}

int main(void) {
    for (int i = 0; i < 10000; i++) {
        previos[i] = -3;
    }

    previos[6174] = 0;

    FILE* f = fopen("matriz.txt", "w+");
    fprintf(f, "{ %i", kaprekar(0));
    for(int i = 1; i < 10000; i++) {
        fprintf(f, ", %i", kaprekar(i));
    }
    fprintf(f, "}\n");
    
    fclose(f);
    return 0;
}