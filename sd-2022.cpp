#include <stdio.h>
#include <string.h>
int main(void){
int dim;
scanf("%d",&dim);
int foto[dim][dim];

for(int y=0;y<dim;y++){
    for(int x=0;x<dim;x++){
        scanf("%i",&foto[y][(dim-1)-x]);
}
}
for(int y=0;y<dim;y++){
    for(int x=0;x<dim;x++){

        printf("%i ",foto[y][x]==1? 0:1);
}
printf("\n");
}
}
    

