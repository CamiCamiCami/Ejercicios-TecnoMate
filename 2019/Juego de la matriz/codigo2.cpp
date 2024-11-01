#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

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

int* mergeSorted(int sorted1[], int largo1, int sorted2[], int largo2) {
    int* ordenado = (int*) malloc(sizeof(int) * (largo1 + largo2));

    for (int i = 0, prim = 0, sec = 0; prim + sec < largo1 + largo2; i++) {
        if (prim >= largo1) {
            ordenado[i] = sorted2[sec++];
            continue;
        }
        if (sec >= largo2) {
            ordenado[i] = sorted1[prim++];
            continue;
        }

        if (sorted1[prim] < sorted2[sec]) {
            ordenado[i] = sorted1[prim++];
        } else {
            ordenado[i] = sorted2[sec++];
        }
    }

    return ordenado;
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

int cantidadBloques;
int largoBloque;
int largoUltimoBloque;
int* ordenarAyudado(int* precalculado[], int lista[], int desde, int hasta) {
    int primerBloque = desde / largoBloque;
    int ultimoBloque = hasta / largoBloque;
    if (primerBloque == ultimoBloque) {
        /* Dentro del mismo bloque */
        int* peorCaso = (int*) malloc(sizeof(int) * (hasta - desde + 1));
        for (int i = 0; i < (hasta - desde + 1); i++) {
            peorCaso[i] = lista[desde + i];
        }
        quicksort(peorCaso, hasta-desde+1);
        return peorCaso;
    }

    int* incAntes = (int*)malloc(sizeof(int) * largoBloque);
    int largoAntes = 0;
    
    for (int dentroBloque = desde % largoBloque; dentroBloque < largoBloque; dentroBloque++, largoAntes++) {
        incAntes[largoAntes] = lista[(primerBloque * largoBloque) + dentroBloque];
    }
    quicksort(incAntes, largoAntes);
    

    int* incDespues = (int*)malloc(sizeof(int) * largoBloque);
    int largoDespues = 0;
    for (int dentroBloque = 0; dentroBloque < (hasta % largoBloque) + 1; dentroBloque++, largoDespues++) {
        incDespues[largoDespues] = lista[(ultimoBloque * largoBloque) + dentroBloque];
    }
    quicksort(incDespues, largoDespues);

    int* merge = mergeSorted(incAntes, largoAntes, incDespues, largoDespues);
    free(incAntes);
    free(incDespues);
    int mergeLargo = largoAntes + largoDespues;
    for (int i = primerBloque + 1; i < ultimoBloque; i++) {
        int* oldMerge = merge;
        merge = mergeSorted(merge, mergeLargo, precalculado[i], largoBloque);
        mergeLargo += largoBloque;
        free(oldMerge);
    }

    return merge;
}

int main(void) {
    int largo, queries;
    scanf("%i %i", &largo, &queries);
    int matriz[largo];
    largoBloque = (int)floor(sqrt((double)largo)); // 31
    cantidadBloques = largo / largoBloque; // = 32       
    largoUltimoBloque = largo % largoBloque;   

    int** precalculado = (int**) malloc(sizeof(int*) * cantidadBloques);
    for (int i = 0; i < cantidadBloques; i++) {
        precalculado[i] = (int*) malloc(sizeof(int) * largoBloque);
    }
    
    if (largoUltimoBloque != 0)  {
        cantidadBloques++;   
        precalculado[cantidadBloques-1] = (int*) malloc(sizeof(int) * largoUltimoBloque);
    }


    int resultados[queries][3];

    for (int i = 0; i < largo; i++) {
        scanf("%d", &matriz[i]);
        precalculado[i/largoBloque][i%largoBloque] = matriz[i];
    }

    for (int i = 0; i < cantidadBloques; i++) {
        quicksort(precalculado[i], i == cantidadBloques - 1 ? largoUltimoBloque : largoBloque);
    } 

    for (int i = 0; i < queries; i++) {
        int desde, hasta, k, gugu, dabriel;
        scanf("%i %i %i %i %i", &desde, &hasta, &k, &gugu, &dabriel);

        int* submatriz = matriz + desde - 1;
        int submatriz_largo = hasta - desde + 1;
        int* orden = ordenarAyudado((int**)precalculado, matriz, desde-1, hasta-1);
        int buscar = orden[k-1];
        free(orden);
        int res = frecuenciaEnMatriz(submatriz, submatriz_largo, buscar);
        resultados[i][0] = buscar;
        resultados[i][1] = res;
        gugu -= res;
        dabriel -= res;
        gugu = gugu < 0 ? -gugu : gugu;
        dabriel = dabriel < 0 ? -dabriel : dabriel;
        if (gugu < dabriel) {
            resultados[i][2] = (int)'G';
        } else if (gugu > dabriel) {
            resultados[i][2] = (int)'D';
        } else {
            resultados[i][2] = (int)'E';
        }
    }

    for (int i = 0; i < queries; i++) {
        printf("%i %i %c\n", resultados[i][0], resultados[i][1], (char)resultados[i][2]);
    }
}