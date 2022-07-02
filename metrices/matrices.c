#include <stdio.h>
#define siz 5
struct ar{
    int arr[siz];
    int n;
};

void set(struct ar* m ,int i,int j,int val){
    if(i==j){
        m->arr[i-1] = val;
    }
}

int get(struct ar m,int i,int j){
    printf("i is %d and j is %d ",i,j);
    if(i==j){

        return m.arr[i-1];
    }else{
        return 0;
    }
}

int display(struct ar m){
    int i,j;
    for(i=1;i<=m.n;i++){
        for(j=1;j<=m.n;j++){
            if(i==j){
                printf("%d ",m.arr[i-1]);
            }else{
                printf("%d ",0);
            }
        }
        printf("\n");
    }

}


int main(){

    struct ar ob;
    ob.n = siz;

    set(&ob,1,1,15);
    set(&ob,2,2,15);
    set(&ob,3,3,30);
    set(&ob,4,4,35);
    set(&ob,5,4,45);
    display(ob);



    return 0;
}
