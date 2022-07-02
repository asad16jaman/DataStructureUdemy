#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int n;
    int *ar;
};


int setData(struct matrix* m,int i,int j,int val){
    if(i>=j){
        m->ar[i*(i-1)/2+(j-1)] = val;
        return 1;
    }
    else{
        return 0;
    }
}

int getData(struct matrix m,int i,int j){
    if(i>=j){
        return m.ar[i*(i-1)/2+(j-1)];
    }
    else{
        return m.ar[j*(j-1)/2+(i-1)];
    }
}

void display(struct matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i>=j){
                printf("%d ",m.ar[i*(i-1)/2+(j-1)]);
            }else{
                printf("%d ",m.ar[j*(j-1)/2+(i-1)]);
            }
        }
        printf("\n");
    }

}




int main(){

    struct matrix mm;
    mm.n = 4;
    int aa[10] = {1,1,2,1,2,3,1,2,3,4};
    mm.ar = &aa;
    display(mm);

    int x = 1;
    int i,j;
    while(x){
        printf("inter index number ....\n");
        scanf("%d%d",&i,&j);
        printf("number is : %d\n",getData(mm,i,j));
        scanf("%d",&x);
    }

    return 0;
}
