#include <stdio.h>
#include <string.h>
int main(void){
    int cant;
scanf("%d",&cant);
char palabra[50];
for(int i=0;i<cant-1;i++){
    scanf("%s",palabra);
    if(strlen(palabra)>3){
        printf("%s ",palabra);
    }
    else {if (palabra[0]=='O' && palabra[1]=='B')
    {
     printf("OBI ");
    }else{
        if (palabra[0]=='U' && palabra[1]=='R'){
            printf("URI ");
        }else
        printf("%s ",palabra);

    }
    }
}
scanf("%s",palabra);
    if(strlen(palabra)>3){
        printf("%s",palabra);
    }
    else {if (palabra[0]=='O' && palabra[1]=='B')
    {
     printf("OBI");
    }else{
        if (palabra[0]=='U' && palabra[1]=='R'){
            printf("URI");
        }else
        printf("%s",palabra);

    }
    }
printf("\n");
}