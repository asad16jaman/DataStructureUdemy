#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Queu{
    int frnt;
    int rear;
    int size;
    struct Node **Q;
};

void createQue(struct Queu* q,int s){
    q->frnt=q->rear = 0;
    q->size = s;
    q->Q = (struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enQue(struct Queu *q,struct Node* l){
    if((q->rear+1)%q->size==q->frnt){
        printf("Que is full......");
    }else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear]= l;
    }
}

struct Node* deQue(struct Queu *q){
    struct Node* x = NULL;
    if(q->rear==q->frnt){
        printf("Que is empty......");
    }else{
        q->frnt = (q->frnt+1)%q->size;
        x = q->Q[q->frnt];
    }
    return x;
}

int isEmpty(struct Queu *q){
    return q->frnt == q->rear;
}

struct Node* root = NULL;

void createTree(){
    struct Node *p,*t;
    int x;
    struct Queu ob;
    createQue(&ob,100);
    printf("inter data for root tree.....\n");
    scanf("%d",&x);
    root= (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->left=root->right = NULL;
    enQue(&ob,root);
    while(!isEmpty(&ob)){
        p = deQue(&ob);
        printf("inter data for left-child.. of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enQue(&ob,t);
        }
        printf("inter data for right-child.. of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enQue(&ob,t);
        }
    }
}


void preorderTraverse(struct Node* root){
    if(root!= NULL){
        printf("%d ",root->data);
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }

}


int main(){

    createTree();

    preorderTraverse(root);


    return 0;
}
