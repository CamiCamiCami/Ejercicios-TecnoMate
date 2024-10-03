#include <iostream>
#include <math.h>

const int MAX_POS = 6;


int ToInt(char* number, int largo) {
    largo -= 1;
    int n = 0;
    for (int i = 0; i <= largo; i++) {
        n += (number[i] - '0') * pow(10, largo-i);
    }
    return n;
}

int Reformatear(char* number, int n) {
    int digitos = (int)ceil(log10((double)n));
    for (int i = digitos-1, j=MAX_POS-1; j < 0; i--, j--) {
        number[j] = i < 0 ? '0' : number[i];
    }
    return digitos;
}

void Next(char* number, int* posiciones) {
    int i = 0;
    for (; number[MAX_POS-1-i] == '9'; i++) 
        number[MAX_POS-1-i] = '0';
    number[MAX_POS-1-i] =  number[MAX_POS-1-i] + 1;
    *posiciones = *posiciones > i ? *posiciones : i;
}

int main(int argc, char *argv[]) {
    int idx = 0;
    char* str = argv[1];
    char temp[MAX_POS];
    int temp_i;
    for (temp_i = 0; str[idx] != ' '; idx++, temp_i++) {
        temp[temp_i] = str[idx];
    }
    idx++;
    int largo = ToInt(temp, temp_i);
    int contador = largo;
    for (temp_i = 0; str[idx] != ' ' && str[idx] != '\0'; idx++, temp_i++) {
        temp[temp_i] = str[idx];
    }
    int primero = ToInt(temp, temp_i);




    for (int remain = largo - primero; remain != 0; remain--) {
        for (int i = 0; str[idx+i] != ' '; i++, str++) {
            if (str[idx+i] == temp[i]) {


            }
        }
    }


}