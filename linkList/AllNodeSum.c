#include <stdio.h>
#include <stdlib.h>

struct Node
{
 int data;
 struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int sum(struct Node* p){
    struct Node *l = p;
    int c = 0;
    while(l!=NULL){
        c += l->data;
        l = l->next;
    }
    return c;
}

int rsum(struct Node* p){
    if(p==NULL){
        return 0;
    }else{
        return rsum(p->next) + p->data;
    }

}

int rsum1(struct Node* p){
    static int l=0;
    if(p!=NULL){
        l += p->data;
        return rsum1(p->next);
    }
    return l;
}
int main(){

    struct Node *temp;
     int A[]={3,5,7,10,25,8,32,2};
     create(A,8);

    printf("%d \n",sum(first));
    printf("%d \n",rsum(first));
    printf("%d \n",rsum1(first));




    return 0;
}
