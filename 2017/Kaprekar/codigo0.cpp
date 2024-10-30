#include <stdlib.h>
#include <stdio.h>

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

char* menor(char num[5]) {
    char* str = quicksort(num, 4);
    str[4] = '\0';
    return str;
}

char* mayor(char num[5]) {
    char* str = antiquicksort(num, 4);
    str[4] = '\0';
    return str;
}

char* menos(char restando[5], char minuendo[5]) {
    bool pido = false;
    char* resultado = (char*)malloc(sizeof(char) * 5);
    for (int i = 4; i >= 0; i--) {
        int n = restando[i];
        int m = minuendo[i];
        int r;
        if (pido) {
            if ((n-1) < m) {
                r = ((n+9) - m);
                pido = true;
            } else {
                r = (n - 1 - m);
                pido = false;
            }
        } else {
            if (n < m) {
                r = ((n + 10) - m);
                pido = true;
            } else {
                r = (n - m);
                pido = false;
            }
        }

        resultado[i] = r + '0';
    }

    resultado[4] = '\0';

    return resultado;
}

bool esKaprekar(char* X) {
    const char kaprekarNum[5] = "6174";
    for (int i = 0; i < 4; i++) {
        if (X[i] != kaprekarNum[i]) {
            return false;
        }
    }
    return true;
}

bool esteRepite(char* X) {
    static char check[5] = "$$$$";
    static int check_vida = 1;

    bool flag = true;
    for (int i = 0; i < 4; i++) {
        if (X[i] != check[i]) {
            flag = false;
            break;
        }
    }

    check_vida--;
    if (check_vida == 0) {
        for (int i = 0; i < 4; i++) {
            check[i] = X[i];
        }
        check_vida = 10;
    }
    return flag;
}

int kaprekar(char* X) {
    int cnt = 0;
    while (!esKaprekar(X)) {
        if (esteRepite(X)) {
            return -1;
        }
        char* may = mayor(X);
        char* men = menor(X);
        X = menos(may, men);
        cnt = cnt + 1;
    }
    return cnt;
}

void alargar(char num[5]) {
    int largo = 0;
    for (; num[largo]; largo++);
    if (largo < 4) {
        for (int i = 4 - largo, n = 0; i < 4; i++, n++) {
            num[i] = num[n];
        }
        for (int i = 0; i < (4 - largo); i++) {
            num[i] = '0';
        }
    }
}



int main(void) {
    int cant;
    scanf("%i", &cant);

    int resultados[cant];
    for (int i = 0; i < cant; i++) {
        char num[5];
        scanf("%s", num);
        alargar(num);
        resultados[i] = kaprekar(num);
    }

    for (int i = 0; i < cant; i++) {
        printf("Caso #%i: %i\n", i+1, resultados[i]);
    }
} 
