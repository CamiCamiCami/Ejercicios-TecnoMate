#include <stdlib.h>
#include <stdio.h>
bool esprimo(int n){
    int cant=1;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(void) {
    int peso;
    scanf("%d",&peso);
    int cont=0,velocidad=0;
    for(int i=0;cont<10;i++){
        if(esprimo(peso+i)){
        velocidad+=peso+i;
        cont++;
        }
    }
    printf("%d km/h  \n",velocidad);
    int horas = 60000000 / velocidad; 
    printf("%d h / %d d",horas,(horas/24));

} 