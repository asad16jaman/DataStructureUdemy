#include <stdlib.h>
#include <stdio.h>

//this file is for collumn major ;

struct matrix{
    int n;
    int *ar;
};


int setData(struct matrix* m,int i,int j,int val){
    if(i>=j){
        m->ar[((m->n*j-1)-((j-2)*(j-1)/2))+(i-j)] = val;
        return 1;
    }
    else{
        return 0;
    }
}

int getData(struct matrix m,int i,int j){
    if(i>=j){
        return m.ar[((m.n*j-1)-((j-2)*(j-1)/2))+(i-j)];
    }
    else{
        return 0;
    }
}

void display(struct matrix m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i>=j){
                printf("%d ",m.ar[((m.n*j-1)-((j-2)*(j-1)/2))+(i-j)]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }

}



int main(){

    struct matrix mm;

    printf("inter dimantion \n");
    scanf("%d",&mm.n);
    mm.ar = (int *) malloc((mm.n*(mm.n+1)/2)*sizeof(int));
    int i,j;
    for(i=1;i<=mm.n;i++){
        for(j=1;j<=mm.n;j++){
                int m;
                scanf("%d",&m);
            if(i>=j){
                mm.ar[((mm.n*j-1)-((j-2)*(j-1)/2))+(i-j)] = m;
            }else{

            }
        }
        printf("\n");
    };

    display(mm);

    /*
    int x[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    mm.n = 5;
    mm.ar = &x;
    display(mm);

    int p = 1;
    while (p){
        int i,j;
        scanf("%d%d",&i,&j);
        printf("%d\n",getData(mm,i,j));
        scanf("%d",&p);
    }
    */


    return 0;
}
