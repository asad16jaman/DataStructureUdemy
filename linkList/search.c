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
struct Node* ptr(struct Node* p,int val){
    if(p->data == val)
        return p;
    struct Node* prev = p;
    struct Node* nex = p->next;
    while(nex!=NULL){
        if(nex->data == val){
            prev->next = nex->next;
            nex->next = p;
            first = nex;
            return nex;
        }else{
            prev = nex;
            nex = nex->next;
        }
    }

};

void Display(struct Node *p)
{
     while(p!=NULL)
     {
        printf("%d ",p->data);
        p=p->next;
     }
}

int main(){

    struct Node *temp;
     int A[]={3,5,7,10,25,8,32,2};
     create(A,8);

    printf("%d \n",ptr(first,10)->data);

    Display(first);
    printf("\n");

    printf("%d \n",ptr(first,10)->data);
    Display(first);






    return 0;
}
