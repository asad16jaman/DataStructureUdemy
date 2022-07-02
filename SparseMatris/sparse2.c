#include <stdio.h>
#include <stdlib.h>

struct Elemen{
    int i;
    int j;
    int x;
};

struct mm{
    int m;
    int n;
    int p;
    struct Elemen* ptr;
};

void createElement(struct mm *ll){
    printf("inter dimantion of sparse.....:\n");
    scanf("%d%d",&ll->m,&ll->n);
    printf("inter number of non zero value :\n");
    scanf("%d",&ll->p);
    ll->ptr = (struct mm*)malloc(ll->p*sizeof(struct mm));
    int i;
    for(i=0;i<ll->p;i++){
        scanf("%d%d%d",&ll->ptr[i].i,&ll->ptr[i].j,&ll->ptr[i].x);
    }
}

void display(struct mm l){
    int i,j,k=0;
    for(i=0;i<l.p;i++){
        for(j=0;j<l.p;j++){
            if(i==l.ptr[k].i && j==l.ptr[k].j){
                printf("%d ",l.ptr[k++].x);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n\n");

}

struct mm* add(struct mm* s1,struct mm* s2){
    struct mm* sum;
    if(s1->m != s2->m && s1->n != s2->n){
        return NULL;
    }
    sum = (struct mm*) malloc(sizeof(struct mm));
    sum->ptr = (struct Elemen*)malloc((s1->p+s2->p)*sizeof(struct Elemen));
    int i,j,k;
    i=j=k=0;
    while(i<s1->p && j<s2->p){
        if(s1->ptr[i].i<s2->ptr[j].i){
            sum->ptr[k++] = s1->ptr[i++];
        }else if(s2->ptr[j].i>s1->ptr[i].i){
            sum->ptr[k++] = s2->ptr[j++];
        }else{
            if(s1->ptr[i].j<s2->ptr[j].j){
                sum->ptr[k++] = s1->ptr[i++];
            }else if(s2->ptr[j].j<s1->ptr[i].j){
                sum->ptr[k++] = s2->ptr[j++];
            }else{
                sum->ptr[k] = s1->ptr[i];
                sum->ptr[k++].x = s1->ptr[i++].x+s2->ptr[j++].x;
            }
        }
    }
    while(i<s1->p){
        sum->ptr[k++] = s1->ptr[i++];
    }
    while(j<s2->p){
        sum->ptr[k++] = s2->ptr[j++];
    }

    sum->m = s1->m;
    sum->n = s1->n;
    sum->p = k;
    return sum;
};





int main(){
    struct mm ob1,ob2;
    //struct mm* ob3;

    createElement(&ob1);
    createElement(&ob2);

   // ob3=add(&ob1,&ob2);
    display(ob1);
   display(ob2);
    printf("after sum.....\n");
    //display(*ob3);




return 0;
}
