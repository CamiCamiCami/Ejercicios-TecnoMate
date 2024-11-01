#include <stdio.h>

int main(void){
for(bool b=true;b==true;){
    int x,y;
    scanf("%d %d",&y,&x);
    if(x==0 && y==0){
        b=false;
    }else
    {
        char imagen[y][x];
        int x2,y2,prop_x,prop_y;

        for (int c = 0; c < y; c++) {
                for (int a = 0; a < x; a++) {
                    
                    scanf(" %c", &imagen[c][a]);  // Espacio antes de %c para ignorar espacios en blanco
                }
            }

        scanf("%d %d",&y2,&x2);
        char imagen2[y][x2];
        char imagen3[y2][x2];
        prop_x=x2/x;
        prop_y=y2/y;
        int co=0;
        for(int c=0;c<y;c++)
        {   co=0;
            for (int a = 0; a < x; a++)
            { 

                for(co;co<prop_x*(a+1);co++)
                {
                 imagen2[c][co]=imagen[c][a];
                }

            }
            
        }
        int co2=0;
            for (int a = 0; a < x2; a++)
            { co2=0;
                for(int c=0;c<y;c++)
            { 

                for(co2;co2<prop_y*(c+1);co2++)
                {
                 imagen3[co2][a]=imagen2[c][a];
                 
                }

            }
            
        }
        for(int c=0;c<y2;c++)
        {
            for (int a = 0; a < x2; a++)
            {
               
                printf("%c",imagen3[c][a]);

            }
            printf("\n");
        }
        printf("\n");
    }
}

}
