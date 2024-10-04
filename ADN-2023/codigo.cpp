#include <stdio.h>
#include <stdlib.h>

int largo;
int alto;
int bugs = 0;

/*
bugxxj
ugxxbx
guxuxx
xbxbgu
xxxuxx
*/

void casoB(int i, int j, char** matriz) {
    printf("      > Investigando Caso B\n");

    //busqueda horizontal
    if (j >= 2) {
        printf("      > Chequea \n");
        if (matriz[i][j-1] == 'u') {
            if (matriz[i][j-2] == 'g') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }

    if (j < largo - 2) {
        if (matriz[i][j+1] == 'u') {
            if (matriz[i][j+2] == 'g') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }

    //busqueda vertical
    if (i >= 2) {
        if (matriz[i-1][j] == 'u') {
            if (matriz[i-2][j] == 'g') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }

    if (i < alto - 2) {
        if (matriz[i+1][j] == 'u') {
            if (matriz[i+2][j] == 'g') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }
}

void casoG(int i, int j, char** matriz) {
    printf("      > Investigando Caso G\n");

    //busqueda horizontal
    if (j >= 2) {
        if (matriz[i][j-1] == 'u') {
            if (matriz[i][j-2] == 'b') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }

    if (j < largo - 2) {
        if (matriz[i][j+1] == 'u') {
            if (matriz[i][j+2] == 'b') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }

    //busqueda vertical
    if (i >= 2) {
        if (matriz[i-1][j] == 'u') {
            if (matriz[i-2][j] == 'b') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }

    if (j < alto - 2) {
        if (matriz[i+1][j] == 'u') {
            if (matriz[i+2][j] == 'b') {
                printf("         ! Encontro Bug \n");
                bugs++;
            }
        }
    }
}

void casoU(int i, int j, char** matriz) {
    printf("      > Investigando Caso U\n");
    if (i >= 0 && i < alto) {
        bool b1 = matriz[i-1][j] == 'b' && matriz[i+1][j] == 'g';
        bool b2 = matriz[i-1][j] == 'g' && matriz[i+1][j] == 'b';
        if (b1 || b2) {
            printf("         ! Encontro Bug \n");
            bugs++;
        }
    }
    if (j >= 0 && j < largo) {
        bool b1 = matriz[i][j-1] == 'b' && matriz[i][j+1] == 'g';
        bool b2 = matriz[i][j-1] == 'g' && matriz[i][j+1] == 'b';
        if (b1 || b2) {
            printf("         ! Encontro Bug \n");
            bugs++;
        }
    }
}


void busqueda(int i, int j, char** matriz) {
    printf("   > Busqueda %c\n", matriz[i][j]);
    switch(matriz[i][j]) {
        case 'b':
            casoB(i,j,matriz);
            break;
        case 'u':
            casoU(i,j,matriz);
            break;
        case 'g':
            casoG(i,j,matriz);
            break;
        default:
            printf("      > No es letra especial\n");
            return;
    }
}

int main(){
    scanf("%d", &largo);
    scanf("%d", &alto);
    int unoDeCadaTres;
    int contadorEmpieza = 0;
    char** matriz = (char**) malloc(sizeof(char*) * alto);
    for ( int i = 0; i < alto; i++) {
        matriz[i] = (char*) malloc(sizeof(char) * largo);
        scanf("%s", matriz[i]);
    }

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < largo; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < alto; i++) {
        unoDeCadaTres = contadorEmpieza;
        for (int j = 0; j < largo; j++) {
            printf("--- Caracter %c ---\n", matriz[i][j]);
            if(!unoDeCadaTres) {
                busqueda(i,j,(char**)matriz);
            }
            unoDeCadaTres = (unoDeCadaTres - 1) % 3;
        }
        contadorEmpieza = (contadorEmpieza - 1) % 3;
    }

    printf("\n\nRESULTADO: %i\n\n", bugs);
    return bugs;
}