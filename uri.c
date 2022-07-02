#include <stdio.h>



int main(){
    int m,i=1,N,C;
    float x = 0.00;
    scanf("%d",&m);
    while(i<=m){
        scanf("%d%d",&N,&C);
        x += ((float)N*C)/(C*100);
        i++;
    }
    printf("%.4f",x/m);



}
