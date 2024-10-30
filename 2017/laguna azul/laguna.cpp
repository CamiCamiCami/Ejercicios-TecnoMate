#include <stdlib.h>
#include <stdio.h>


int main(void) {
    int cant_pajaros,cant_sitios,cant_vuelos,vuelo,vuelo_aux,cant_vueltas=1,cant_vueltas_aux=0;
    scanf("%i %i", &cant_pajaros, &cant_sitios);

    for(int x=0; x<cant_pajaros;x++){
    scanf("%d",&cant_vuelos);
    scanf("%d",&vuelo);
    for (int i = 0; i < (cant_vuelos-1); i ++) {
        scanf("%i", &vuelo_aux);
        if(vuelo_aux < vuelo){
         cant_vueltas++;
        }   
        vuelo=vuelo_aux;
    }
    if (cant_vueltas>cant_vueltas_aux){
        cant_vueltas_aux= cant_vueltas;
    }

}
printf("%d",cant_vueltas_aux);

} 