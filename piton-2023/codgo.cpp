
#include <stdio.h>


int main(void) {
    double largo;
    scanf("%lf", &largo);
    double resultado = (largo*largo) + 0.5*largo*(largo+1)*(largo-1-(2*largo + 1) / 3);
    resultado = 2 * resultado + largo;
    printf("%i\n", (int)resultado);
}