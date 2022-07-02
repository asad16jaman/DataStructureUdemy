#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* serce(struct Node* root,int key){
    if(root!=NULL){
        if(root->data==key){
            return root;
        }else if(root->data>key){
            serce(root->left,key);
        }else{
            serce(root->right,key);
        }
    }
};



struct Node* insertNode(struct Node* root,int key){
    if(root!=NULL){
        if(root->data==key){
            return;
        }else if(root->data>key){
            if(root->left!=NULL){
                insertNode(root->left,key);
            }else{
                struct Node* p = (struct Node*) malloc(sizeof(struct Node));
                p->data = key;
                p->left=p->right = NULL;
                root->left = p;
                return p;
            }
        }else{
            if(root->right!=NULL){
                insertNode(root->right,key);
            }else{
                struct Node* p = (struct Node*) malloc(sizeof(struct Node));
                p->data = key;
                p->left=p->right = NULL;
                root->right = p;
                return p;
            }
        }
    }

};

//insert node using loop;
struct Node* ins(struct Node* root,int key){
    struct Node* r = NULL;
    struct Node* p;
    if(root == NULL){
        p = (struct Node*) malloc(sizeof(struct Node));
        p->data = key;
        p->left = p->right = NULL;
        return p;
    }

    while(root != NULL){
        r = root;
        if(root->data==key){
            return ;
        }else if(root->data>key){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    p = (struct Node*) malloc(sizeof(struct Node));
    p->data = key;
    p->left = p->right = NULL;
    if(r->data>key){
        r->left = p;
    }else{
        r->right = p;
    }
    return p;
};


 void inorder(struct Node* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
 }

int main(){

    struct Node *therty,*ten,*one,*fiftin,*fourty,*thtyfive,*fifty;
    therty = (struct Node*)malloc(sizeof(struct Node));
    ten = (struct Node*)malloc(sizeof(struct Node));
    one = (struct Node*)malloc(sizeof(struct Node));
    fiftin = (struct Node*)malloc(sizeof(struct Node));
    fourty = (struct Node*)malloc(sizeof(struct Node));
    thtyfive = (struct Node*)malloc(sizeof(struct Node));
    fifty = (struct Node*)malloc(sizeof(struct Node));

    therty->data = 30;
    therty ->left = ten;
    therty->right = fourty;

    ten->data = 10;
    ten->left = one;
    ten->right = fiftin;

    one->data = 1;
    one->left = NULL;
    one->right = NULL;

    fiftin->data = 15;
    fiftin->left =NULL;
    fiftin->right = NULL;

    fourty->data = 40;
    fourty->left = thtyfive;
    fourty->right = fifty;

    thtyfive->data = 35;
    thtyfive->left = NULL;
    thtyfive->right = NULL;

    fifty->data = 50;
    fifty->left = NULL;
    fifty->right = NULL;

    /*

    int p;
    printf("inter key for search.....\n");
    scanf("%d",&p);

    if(serce(therty,p)){
        printf("%d....",serce(therty,p)->data);
    }else{
        printf("not fount");
    }


    */

    inorder(therty);

    printf("\n");
    ins(therty,31);
    inorder(therty);



    return 0;
}
