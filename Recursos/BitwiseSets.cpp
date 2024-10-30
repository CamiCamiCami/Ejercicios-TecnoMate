#include <stdlib.h>
#include <stdio.h>

struct __set {
    u_int8_t* registro;
    int largo_potencial;
};

typedef struct __set* Set;

Set initSet(int mayor_numero_posible) {
    Set new_set = (Set) malloc(sizeof(struct __set));
    new_set->largo_potencial = mayor_numero_posible + ((8 - (mayor_numero_posible % 8)) % 8);
    new_set->registro = (u_int8_t*) malloc(new_set->largo_potencial);
    return new_set;
}

Set addValue(Set set, int valor) {
    int reg_pos = valor / 8;
    u_int8_t* reg = (u_int8_t*) set->registro + reg_pos;
    int offset = 8 - (valor % 8) - 1;
    u_int8_t mask = 0b00000001 << offset;
    *reg = *reg | mask;
    return set;
}

Set mergeSets(Set first, Set second) {
    Set menor = first->largo_potencial < second->largo_potencial ? first : second;
    Set mayor = first->largo_potencial > second->largo_potencial ? first : second;

    Set merge = initSet(mayor->largo_potencial);

    u_int8_t* reg = merge->registro;
    for (int i = 0; i < menor->largo_potencial; i++) {
        *(reg + i) = *(menor->registro + i) | *(mayor->registro + i);
    }
    for (int i = menor->largo_potencial; i < mayor->largo_potencial; i++) {
        *(reg + i) = *(mayor->registro + i);
    }

    return merge;
}

void printSet(Set set) {
    printf("{");
    bool printed_smt = false;
    long long numero = 0;
    for (int i = 0; i < set->largo_potencial; i++) {
        u_int8_t valores = *(set->registro + i);
        for (int j = 0; j < 8; j++) {
            int offset = 8 - (j % 8) - 1;
            u_int8_t mask = 0b00000001 << offset;
            if (valores & mask) {
                if (printed_smt) {
                    printf(", ");
                } else {
                    printed_smt = true;
                }

                printf("%lli", numero);
            }
            numero++;
        }
    }
    printf("}\n");
}

void freeSet(Set set) {
    free(set->registro);
    free(set);
}