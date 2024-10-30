


struct __preprocesado {
    int* data;
    Set* preresultados;
    int cant_bloques;
    int largo_bloque;
};

typedef struct __preprocesado* Preprocesado;

Preprocesado preprocesar(int data[], int largo) {
    Preprocesado pre = (Preprocesado) malloc(sizeof(struct __preprocesado));
    pre->cant_bloques = ceil(sqrt((double)largo));
    pre->largo_bloque = floor(sqrt((double)largo));
    pre->data = (int*) malloc(sizeof(int) * largo);
    int mayor_numero = 0;
    for (int i = 0; i < largo; i++) {
        pre->data[i] = data[i];
        mayor_numero = data[i] > mayor_numero ? data[i] : mayor_numero;
    }

    pre->preresultados = (Set*) malloc(sizeof(Set) * pre->cant_bloques);
    for (int i = 0; i < pre->cant_bloques - 1; i++) {
        pre->preresultados[i] = initSet(mayor_numero);
        for (int j = 0; j < pre->largo_bloque; j++) {
            addValue(pre->preresultados[i], *(pre->data + (i * pre->largo_bloque) + j));
        }
    }

    return pre;
}

Set 

int encontrarRango(Preprocesado pre, int desde, int hasta) {

}




int main(void) {
    int numeros1[7] = {0, 1, 3, 4, 6, 7, 10};
    Set set1 = initSet(10);
    for (int i = 0; i < 7; i++) {
        set1 = addValue(set1, numeros1[i]);
    }
    int numeros2[3] = {0, 2, 7};
    Set set2 = initSet(7);
    for (int i = 0; i < 3; i++) {
        set2 = addValue(set2, numeros2[i]);
    }
    printSet(set1);
    printSet(set2);
    printSet(mergeSets(set1, set2));
}


