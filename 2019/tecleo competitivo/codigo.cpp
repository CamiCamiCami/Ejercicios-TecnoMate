#include <stdio.h>
#include <stdlib.h>

int* posicion;

void ejecutarRonda(const int* estadsticas[], int participantes, int ronda, int largoTexto) {
    if (participantes == 1) {
        posicion[estadsticas[0][2]] = ronda;
        return;
    }
    const int* estadsticasSig[participantes/2];
    for (int i = 0; 2*i < participantes; i++) {
        bool ganoPri = estadsticas[2*i][0] + estadsticas[2*i][1] * largoTexto <= estadsticas[2*i+1][0] + estadsticas[2*i+1][1] * largoTexto;
        if (ganoPri) {
            estadsticasSig[i] = estadsticas[2*i];
            posicion[2*i+1] = ronda;
        } else {
            estadsticasSig[i] = estadsticas[2*i+1];
            posicion[2*i] = ronda;
        }
    }

    ejecutarRonda(estadsticasSig, participantes/2, ronda+1, largoTexto*2);
}

int main(void) {
    int participantes;
    scanf("%i", &participantes);
    int* estadisticas[participantes];
    posicion = (int*) malloc(sizeof(int) * participantes);
    for (int i = 0; i < participantes; i++) {
        estadisticas[i] = (int*) malloc(sizeof(int) * 3);
        scanf("%i %i", &estadisticas[i][0], &estadisticas[i][1]);
        estadisticas[i][2] = i;
    }
    
    int largoTexto = 0;
    char c = ' ';
    scanf("%c", &c);
    while(c != '\n') {
        largoTexto++;
        scanf("%c", &c);
    }

    ejecutarRonda((const int**)estadisticas, participantes, 1, largoTexto);
}