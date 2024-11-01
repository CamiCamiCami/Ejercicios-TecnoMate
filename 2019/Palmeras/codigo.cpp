#include <stdio.h>
#include <cmath>

struct __circulo {
    int radio;
    int x;
    int y;
};

typedef struct __circulo* Circulo;

Circulo crearTresPuntos(double x1, double y1, double x2, double y2, double x3, double y3) {
    Circulo circulo = (Circulo) malloc(sizeof(struct __circulo));

    circulo->

}

int main(void) {
    int largo;
    scanf("%i", &largo);
    double posY[largo];
    double posX[largo];
    double centroMasasX = 0, centroMasasY = 0;

    for (int i = 0; i < largo; i++) {
        scanf("%lf %lf", &posX[i], &posY[i]);
    }

    double maxDistancia = 0;
    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo; j++) {
            double distancia = sqrt(pow(posX[i] - posX[j], 2) + pow(posY[i] - posY[j], 2));
            if (distancia > maxDistancia) {
                centroMasasX = (posX[i] + posX[j]) / 2.0;
                centroMasasY = (posY[i] + posY[j]) / 2.0;
                maxDistancia = distancia;
            }
        }
    }

    maxDistancia = 0;
    for (int i = 0; i < largo; i++) {
        double distancia = sqrt(pow(posX[i] - centroMasasX, 2) + pow(posY[i] - centroMasasY, 2));
        if (distancia > maxDistancia) {
            maxDistancia = distancia;
        }
    }

    double radio = maxDistancia;
    double perimetro = 2 * 3.14 * radio;
    double cable = perimetro * 4;

    printf("%.2f %.2f %.2f %.2f\n", centroMasasX, centroMasasY, radio, cable);
} 