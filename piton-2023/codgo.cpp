
#include <stdio.h>


int main(void) {
    double largo;
    scanf("%lf", &largo);
    double resultado = ((largo*largo*largo)/6) + ((largo*largo)/2) - ((2*largo)/3);
    resultado = 2 * resultado + largo;
    printf("%i\n", (int)resultado);
}