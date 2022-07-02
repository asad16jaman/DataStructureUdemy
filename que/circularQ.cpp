#include <iostream>

using namespace std;

class CerQue{
    int frnt;
    int rear;
    int siz;
    int *Q;

public:
    CerQue(){
        frnt = rear = 0;
        siz = 5;
        Q = new int[siz];
    }

    CerQue(int siz){
        frnt = rear = 0;
        this->siz = siz;
        Q = new int[this->siz];
    }
    int enQue(int val);
    int deQue();
    void display();



};

int CerQue :: enQue(int val){
    if((rear+1)%siz==frnt){
        cout<<"Que is full"<<endl;
        return 0;
    }else{
        rear = (rear+1)%siz;
        Q[rear] = val;
        //cout<<"rear is : "<<rear<<"front is : "<<frnt<<endl;
        return 1;
    }
}

int CerQue :: deQue(){
    int x = -1;
    if(frnt==rear){
        cout<<"Que is empty"<<endl;

    }else{
        frnt = (frnt+1)%siz;
        x = Q[frnt];
    }
    return x;
}

void CerQue :: display(){
    int i = frnt+1;
    do{
        cout<<Q[i]<<" ";
        i = (i+1)%siz;
    }while(i!=(rear+1)%siz);
}

int main(){

    CerQue ob;

    ob.enQue(10);
    ob.enQue(10);
    ob.enQue(10);
    ob.enQue(10);
    ob.enQue(10);
    ob.enQue(10);
    ob.display();


    return 0;
}
