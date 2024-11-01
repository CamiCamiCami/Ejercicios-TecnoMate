#include <stdio.h>
#include <stdlib.h>

int* largoDesde;
int* largoHacia;
int** conexionHacia;
int** conexionDesde;
bool* conectados;

void marcarAlcanzado(int empresa) {
    if (conectados[empresa]) {
        return;
    }

    conectados[empresa] = true;
    for (int i = 0; i < largoHacia[empresa]; i++) {
        marcarAlcanzado(conexionHacia[empresa][i]);
    }
}

void marcarBucleAlcanzado(int empresa) {
    if (conectados[empresa]) {
        return;
    }

    conectados[empresa] = true;
    for (int i = 0; i < largoHacia[empresa]; i++) {
        marcarBucleAlcanzado(conexionHacia[empresa][i]);
    }
    for (int i = 0; i < largoDesde[empresa]; i++) {
        marcarBucleAlcanzado(conexionDesde[empresa][i]);
    }
}

int main(void) {
    int empresas, caminos, centro, caminosEmergencia = 0;
    scanf("%i %i %i", &empresas, &caminos, &centro);
    centro--;

    largoDesde = (int*) malloc(sizeof(int) * empresas);
    largoHacia = (int*) malloc(sizeof(int) * empresas);
    conexionHacia = (int**) malloc(sizeof(int*) * empresas);
    conexionDesde = (int**) malloc(sizeof(int*) * empresas);
    conectados = (bool*) malloc(sizeof(bool) * empresas);
    
    for (int i = 0; i < empresas; i++) {
        largoDesde[i] = 0;
        largoHacia[i] = 0;
        conectados[i] = false;
    }
    conectados[centro] = true;

    int desdeAux[caminos], haciaAux[caminos];
    for (int i = 0; i < caminos; i++) {
        int desde, hacia;
        scanf("%i %i", &desde, &hacia);
        desde--;
        hacia--;
        largoDesde[hacia]++;
        largoHacia[desde]++;
        desdeAux[i] = desde;
        haciaAux[i] = hacia;
    }

    int haciaIdxAux[empresas], desdeIdxAux[empresas];
    for (int i = 0; i < empresas; i++) {
        conexionHacia[i] = (int*) malloc(sizeof(int) * largoHacia[i]);
        conexionDesde[i] = (int*) malloc(sizeof(int) * largoDesde[i]);
        haciaIdxAux[i] = 0;
        desdeIdxAux[i] = 0;
    }

    for (int i = 0; i < caminos; i++) {
        conexionDesde[haciaAux[i]][desdeIdxAux[haciaAux[i]]++] = desdeAux[i];
        conexionHacia[desdeAux[i]][haciaIdxAux[desdeAux[i]]++] = haciaAux[i];
    }

    for (int i = 0; i < largoHacia[centro]; i++) {
        marcarAlcanzado(conexionHacia[centro][i]);
    }

    for (int i = 0; i < empresas; i++) {
        if (!conectados[i] && largoDesde[i] == 0) {
            caminosEmergencia++;
            marcarAlcanzado(i);
        }
    }

    for (int i = 0; i < empresas; i++) {
        if (largoHacia[i] > 0 && !conectados[i]) {
            caminosEmergencia++;
            marcarBucleAlcanzado(i);
        }
    }

    printf("%i\n", caminosEmergencia);
}
