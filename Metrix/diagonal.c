#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int n;
    int* ar;
};

int setData(struct matrix *m,int i,int j,int val){
    if(i==j){
        m->ar[i-1] = val;
        return 1;
    }
    return 0;
}

int getData(struct matrix m,int i,int j){
    if(i==j){
        return m.ar[i-1];
    }
    else{
        return 0;
    }

}

void display(struct matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i==j){
                printf("%d ",m.ar[i-1]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}





int main(){
    struct matrix m1;
    printf("Inter dimantion of matrix: \n");
    scanf("%d",&m1.n);
    m1.ar = (int *) malloc(m1.n*sizeof(int));
    int i;
    for(i=0;i<m1.n;i++){
     scanf("%d",&m1.ar[i]);
    }
    display(m1);



    return 0;
}
