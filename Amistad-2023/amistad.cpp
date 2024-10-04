#include <iostream>
#include <math.h>
#include <string.h>

const int MAX_POS = 6;
int largox;

int ToInt(char* number, int largo) {
    largo -= 1;
    int n = 0;
    for (int i = 0; i <= largo; i++) {
        n += (number[i] - '0') * pow(10, largo-i);
    }
    return n;
}

int Reformatear(char* number) {
    const int end = MAX_POS - 1;
    int digitos = strlen(number) - 1;
    char aux[digitos+1];
    strcpy(aux, number);
    for(int i = 0; i < MAX_POS; i++) {
        number[i] = i < end - digitos ? '0' : aux[i - (end - digitos)];
    }
    return digitos;
}

void Next(char* number, int* posiciones) {
    const int end = MAX_POS-1;
    int i = 0;
    for (; number[MAX_POS-1-i] == '9'; i++) 
        number[MAX_POS-1-i] = '0';
    number[end-i] = number[end-i] + 1;
    *posiciones = *posiciones > i ? *posiciones : i;
}

int main(int argc, char *argv[]) {
    scanf("%i", &largox);


    char esperado[MAX_POS];
    int i = 0;
    getc(stdin);
    for (char c = (char)getc(stdin); c != ' '; c = (char)getc(stdin), i++) {
        esperado[i] = c;
    }
    esperado[i] = '\0';

    printf("%s\n", esperado);
    int digitos = Reformatear(esperado);
    int desde = MAX_POS - 1 - (digitos + 1);
    printf("%i\n%i\n%i\n%s\n", digitos, i, desde, esperado);
    Next(esperado, &desde);
    printf("%i\n%s\n", desde, esperado);
}