#include <stdio.h>
#include <stdlib.h>

struct arra{
    int size;
    int *arr;
};

void setData(struct arra* a,int i,int j,int val){
    if(i>=j){
        a->arr[i*(i-1)/2+j-1]= val;
    }
}

int getData(struct arra a,int i,int j){
    if(i>=j){
        return a.arr[i*(i-1)/2+j-1];
    }else{
        return 0;
    }
}

void display(struct arra a){
    int i,j;
    printf("%d....\n",a.size);
    for(i=1;i<=a.size;i++){
        for(j=1;j<=a.size;j++){
            printf("%d ",getData(a,i,j));
        }
        printf(";\n");
    }

}





int main(){
    struct arra m;
    printf("inter the dimention of 2D array.....: ");
    scanf("%d",&m.size);
    m.arr = (int *) malloc((m.size*(m.size+1)/2)*sizeof(int));

    int i,j,v;
    for(i=1;i<=m.size;i++){
        for(j=1;j<=m.size;j++){
            scanf("%d",&v);
            setData(&m,i,j,v);
        }
    };

    display(m);



    return 0;
}

