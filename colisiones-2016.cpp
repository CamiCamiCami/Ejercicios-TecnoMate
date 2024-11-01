#include <stdio.h>

int main(void){
int ax0,ay0,ax1,ay1;
int bx0,by0,bx1,by1;
scanf("%i %i %i %i",&ax0,&ay0,&ax1,&ay1);

scanf("%i %i %i %i",&bx0,&by0,&bx1,&by1);
printf("%i",((ax0>bx0 && ax0<bx1) && (ay1>by0 && ay1<by1)) || ((ax1>bx0 && ax1<bx1) && (ay1>by0 && ay1<by1)) || ((ax1>bx0 && ax1<bx1) && (ay0>by0 && ay0<by1)) ||((ax0>bx0 && ax0<bx1) && (ay0>by0 && ay0<by1))  );

}
