#include <stdio.h>


int main(void) {
    int casos;
    scanf("%i", &casos);
    int res[casos]; 
    for (int i = 0; i < casos; i++) {
        int largo;
        scanf("%i", &largo);
        res[i] = (3*largo*largo) - (3*largo) + 1;
    }

    for (int i = 0; i < casos; i++) 
        printf("%i\n", res[i]);
    
    return 0;
}