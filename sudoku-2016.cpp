#include <stdio.h>

bool funciona(bool lista[9]){
    for(int i=0;i<9;i++){
        if(lista[i]==false){
            return false;
        }
    }
    return true;
}

int main(void){
    int instancias;
scanf("%d",&instancias);

int sudoku[9][9],sudoku2[9][9],sudoku3[9][9];
for(int a=0;a<instancias;a++){
    printf("Instancia %d\n",a+1);
for(int x=0;x<9;x++){
    for(int y=0;y<9;y++){
        scanf("%d",&sudoku[x][y]);
        sudoku2[y][x]=sudoku[x][y];
        sudoku3[(3*(y/3))+(x/3)][((x%3)*3+(y%3))]= sudoku[x][y];
    }

}
bool flag=true;
for(int x=0;x<9;x++){
    bool bitmap[9]={false,false,false,false,false,false,false,false,false };
    bool bitmap2[9]={false,false,false,false,false,false,false,false,false };
    bool bitmap3[9]={false,false,false,false,false,false,false,false,false };
    for(int y=0;y<9;y++){
        bitmap[sudoku[x][y]-1]=true;
        bitmap2[sudoku2[x][y]-1]=true;
        bitmap3[sudoku3[x][y]-1]=true;
    }
    if((funciona(bitmap) !=true) || (funciona(bitmap2) != true) || (funciona(bitmap3) != true)){
    printf("NAO ");
    flag=false;
    x=9;
    }
}
if(flag){
    printf("SIM ");
}
if(a<instancias-1){printf("\n\n");}
}
}