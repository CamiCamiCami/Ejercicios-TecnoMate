#include <stdio.h>
int casos;

long encontrarTiempo(int pasos_alto, int pasos_ancho) {
    long tiempo = 0;
    int paso_largo = pasos_alto < pasos_ancho ? pasos_ancho : pasos_alto;
    int paso_corto = pasos_alto >= pasos_ancho ? pasos_ancho : pasos_alto;
    for (tiempo += paso_largo; tiempo % paso_corto != 0; tiempo += paso_largo);
    return tiempo;
}



int main(void) {

    scanf("%i", &casos);
    long resultados[casos];

    for (int i = 0; i < casos; i++) {
        int pantalla_alto, pantalla_ancho;
        int logo_alto, logo_ancho;
        scanf("%i %i", &pantalla_alto, &pantalla_ancho);
        scanf("%i %i", &logo_alto, &logo_ancho);
        resultados[i] = encontrarTiempo(pantalla_alto - logo_alto, pantalla_ancho - logo_ancho);
    }

    for (int i = 0; i < casos; i++) {
        printf("%li\n", resultados[i]);
    }
    return 0;

    fprintf(stdout, "hola");
}