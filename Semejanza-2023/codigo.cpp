#include <stdio.h>
#include <stdlib.h>

char* conseguir_scanf_str(int largo) {
    int str_largo = 3*largo;
    char* str = (char*) malloc(sizeof(char) * str_largo);
    int j = 0;
    for (int i = 0; i < largo-1; i++) {
        str[j++] = '%';
        str[j++] = 'i';
        str[j++] = ' ';
    }
    str[j++] = '%';
    str[j++] = 'i';
    str[j++] = '\0';

    return str;
}

void salir(int res) {
    printf("%i", res);
    exit(0);
 }

int main(void) {
    int largo;
    scanf("%i", &largo);
    bool cumple[largo];
    int fila[largo];
    for (int i = 0; i<largo; i++)
        cumple[i] = true;
    
    for (int i = 0; i < largo; i++) {
        int min = 1001;
        for (int j = 0; j < largo; j++){
            if (j == largo-1) {
                scanf("%i", &fila[j]);
            } else {
                scanf("%i ", &fila[j]);
            }
            min = fila[j] < min ? fila[j] : min;
        }

        bool existe_pos = false;
        for (int j = 0; j < largo; j++){
            existe_pos = existe_pos || cumple[j];
            if(cumple[j]) {
                cumple[j] = (fila[j] % min) == 0;
            }
        }

        if (!existe_pos) {
            salir(0);
        }
    }

    int cant = 0;
    for (int i = 0; i < largo; i++) {
        if (cumple[i]) {
            cant++;
        }
    }

    salir(cant);
}


