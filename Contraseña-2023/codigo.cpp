#include <stdio.h>

int cantContraseñas;

bool esMinuscula(char c) {
    return c >= 'a' && c <= 'z';
}

bool esMayuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

bool esPrimo(char c) {
    switch (c)
    {
    case '2':
    case '3':
    case '5':
    case '7':
        return true;
    default:
        return false;
    }
}



bool scanContraseña() {
    int largo;
    scanf("%i", &largo);
    char contrasena[largo];
    scanf("%s", contrasena);

    if(largo < 4 || largo > 32 || (largo % 2 == 0)) {
        return false;
    }

    if (!esMinuscula(contrasena[0]) || !esMayuscula(contrasena[largo-1]) || !esPrimo(contrasena[(largo-1)/2])) {
        return false;
    }

    return true;
}


int main(void) {
    scanf("%i", &cantContraseñas);

    while (!feof(stdin))
    {
        if(scanContraseña()) {
            printf("CONTRASENA SEGURA\n");
        } else {
            printf("CONTRASENA NO SEGURA\n");
        }
    }
}