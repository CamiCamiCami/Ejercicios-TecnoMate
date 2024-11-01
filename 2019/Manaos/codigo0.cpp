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
        conexionHacia[i] = (int*) malloc(sizeof(int) * caminos);
        conexionDesde[i] = (int*) malloc(sizeof(int) * caminos);
        largoDesde[i] = 0;
        largoHacia[i] = 0;
        conectados[i] = false;
    }
    conectados[centro] = true;

    for (int i = 0; i < caminos; i++) {
        int desde, hacia;
        scanf("%i %i", &desde, &hacia);
        desde--;
        hacia--;
        conexionDesde[hacia][largoDesde[hacia]++] = desde;
        conexionHacia[desde][largoHacia[desde]++] = hacia;
    }

    /*
    for(int i = 0; i < empresas; i++) {
        printf("--- EMPRESA %i ---\n", i+1);
        printf("    > DESDE:\n");
        for (int j = 0; j < largoDesde[i]; j++) {
            printf("> %i\n", conexionDesde[i][j]+1);
        }
        printf("    > HASTA:\n");
        for (int j = 0; j < largoHacia[i]; j++) {
            printf("> %i\n", conexionHacia[i][j]+1);
        }
    }
    */

   printf("-----  <>  -----\n");
   for(int i = 0; i < empresas; i++) {
        printf("> EMPRESA %i: %s\n", i+1, (conectados[i] ? "CONECTADA" : "DESCONECTADA"));
    }

    for (int i = 0; i < largoHacia[centro]; i++) {
        marcarAlcanzado(conexionHacia[centro][i]);
    }

    printf("-----  <>  -----\n");
    for(int i = 0; i < empresas; i++) {
        printf("> EMPRESA %i: %s\n", i+1, conectados[i] ? "CONECTADA" : "DESCONECTADA");
    }


    for (int i = 0; i < empresas; i++) {
        if (largoDesde[i] == 0) {
            caminosEmergencia++;
            marcarAlcanzado(i);
        }
    }

    printf("-----  <>  -----\n");
    for(int i = 0; i < empresas; i++) {
        printf("> EMPRESA %i: %s\n", i+1, conectados[i] ? "CONECTADA" : "DESCONECTADA");
    }

    for (int i = 0; i < empresas; i++) {
        if (largoHacia[i] > 0 && !conectados[i]) {
            caminosEmergencia++;
            marcarAlcanzado(i);
        }
    }

    printf("-----  <>  -----\n");
    for(int i = 0; i < empresas; i++) {
        printf("> EMPRESA %i: %s\n", i+1, conectados[i] ? "CONECTADA" : "DESCONECTADA");
    }

    printf("RESULTADO = %i\n", caminosEmergencia);
}
