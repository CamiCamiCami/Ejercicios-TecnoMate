#include <stdio.h>
#include <stdlib.h>

int final_bueno(int resultado) {
    printf("RESULTADO = %i\n", resultado);
    exit(0);
}

int final_malo() {
    printf("RESULTADO = -1\n");
    exit(0);
}

int main(void) {
    int cant_tipos;
    scanf("%i", &cant_tipos);

    int tipos[cant_tipos];
    for (int i = 0; i < cant_tipos; i++) {
        scanf(" %i", &tipos[i]);
        if (tipos[i] >= 2) {
            final_bueno(cant_tipos + 1);
        }
    }
    final_malo();
}