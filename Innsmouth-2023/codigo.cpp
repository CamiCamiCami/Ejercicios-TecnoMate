#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>

char tabs[10] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
int tabidx=0;
void quicksort(int lista[], int largo) {
    tabs[tabidx++] = '\t';
    printf("%sLista:\n%s", tabs, tabs);
    for (int i = 0; i < largo; i++) {
        printf("%i ", lista[i]);
    }
    printf("\n");

    if (largo < 2) {
        printf("%sNada Que ordenar\n", tabs);
        tabs[--tabidx] = '\0';
        return;
    }

    int numero = lista[0];
    int menores[largo], mayores[largo], m_largo = 0, M_largo = 0;

    for (int i = 1; i < largo; i++) {
        if (lista[i] < numero) {
            menores[m_largo] = lista[i];
            m_largo++;
        } else {
            mayores[M_largo] = lista[i];
            M_largo++;
        }
    }

    quicksort(menores, m_largo);
    printf("%sMenores:\n%s", tabs, tabs);
    for (int i = 0; i < m_largo; i++) {
        printf("%i ", menores[i]);
    }
    printf("\n");
    quicksort(mayores, M_largo);
    printf("%sMayores:\n%s", tabs, tabs);
    for (int i = 0; i < M_largo; i++) {
        printf("%i ", mayores[i]);
    }
    printf("\n");

    int idx = 0;
    for(int i = 0; i<M_largo; i++) {
        lista[idx++] = mayores[i];
    }
    lista[idx++] = numero;
    for(int i = 0; i<m_largo; i++) {
        lista[idx++] = menores[i];
    }
    tabs[--tabidx] = '\0';
}


int main(void) {
    int cantidad;
    scanf("%i", &cantidad);
    int numeros[cantidad];

    for (int i = 0; i < cantidad; i++) {
        scanf("%i", &numeros[i]);
    }

    quicksort(numeros, cantidad);

    int resultado = 0;
    for (int i = 0; i < cantidad; i+=2) {
        resultado += numeros[i];
    }

    printf("RESULTADO = %i\n", resultado);
}