#include <stdio.h>
#include <string.h>


int casos;

double calcular_probabilidad(char tipo[12], int dificultad, int habilidad) {
    double normal = (21.0 + habilidad - dificultad) / 20.0;
    double anti_normal = 1-normal;

    switch (strlen(tipo))
    {
    case 6:
        return normal;
    case 7:
        return 1 - (anti_normal * anti_normal);
    case 10:
        return normal*normal;
    default:
        return -1;
    }
}


int main(void) {
    scanf("%i", &casos);
    double resultados[casos];

    for (int i = 0; i < casos; i++) {
        int dificultad, habilidad;
        char tipo_str[12];
        scanf("%i %i", &dificultad, &habilidad);
        scanf("%s", tipo_str);
        resultados[i] = calcular_probabilidad(tipo_str, dificultad, habilidad);
    }

    for (int i = 0; i<casos; i++)
        printf("%lf\n", resultados[i]);
}