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

int max(struct Node* p){
    struct Node *l = p;
    int c = p->data;
    while(p!=NULL){
        if(p->data>c){
            c = p->data;
        }
        p = p->next;
    }
    return c;
}

int rmax(struct Node* p){
    int x;
    if(p==NULL){
        return 0;
    }else{
        x = rmax(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }

}







int main(){

    struct Node *temp;
     int A[]={3,5,7,10,25,8,32,2};
     create(A,8);
    printf("%d",rmax(first));



    return 0;
}
