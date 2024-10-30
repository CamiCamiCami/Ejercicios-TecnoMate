#include <stdlib.h>
#include <string.h>
#include <stdio.h>


bool esNumero(char c) {
    return c >= '0' && c <= '9'; 
}

void leer(char nombre[100], char num[100]) {
    char c;
    int i = 0;
    for (c = getc(stdin); !esNumero(c); c = getc(stdin), i++) {
        nombre[i] = c;
    }
    nombre[i] = '\0';
    for (i = 0; c != '\n'; c = getc(stdin), i++) {
        num[i] = c;
    } 
    num[i] = '\0';
}

int main(void) {
    int casos;
    char altura_pared[4];
    scanf("%d %s",&casos,altura_pared);
    for(int b=0;b<casos;b++){
    char nombre[10][100];

    for(int i=0;i<10;i++){
    scanf("%s",nombre[i]);

    if(nombre[i][0]>='0' && nombre[i][0]<='9'){

    if(strlen(nombre[i])>strlen(altura_pared)){

    for(int x=0;x<i;x++){
        printf("%s ",nombre[x]);
    }

    printf("%s",nombre[i]);

    break;
    }else{
    if(strlen(nombre[i])==strlen(altura_pared)){

    for(int x=0;x<strlen(nombre[i]);x++){
        if(nombre[i][x]>altura_pared[x]){
            for(int y=0;y<i;y++){
        printf("%s ",nombre[y]);
                 }

    printf("%s",nombre[i]);

        }
        else{
             break;
                 }
    }
    break;

    }else{
    break;
    }
    }
    }

    }
} 
}