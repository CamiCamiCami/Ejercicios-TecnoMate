#include <stdio.h>
#include <string.h>

int main(void){
int sillas,tamao;
scanf("%d %d\n",&sillas,&tamao);
char frase[tamao]; 
scanf("%[^\n]",frase);  
int letras=0;
printf("%s\n",frase);
for(int i=0;i<tamao;i++){
   
    if((frase[i]>='a'&&frase[i]<='z') || (frase[i]>='A'&&frase[i]<='Z') ){
        letras+=1;
    }
}
printf("%d\n",letras);
int resultado;
resultado = (letras/2) % 3 == 0 ? 3 : (letras/2) % 3;
printf("%d",resultado);
}
