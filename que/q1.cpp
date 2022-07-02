#include <iostream>
using namespace std;

class Que{
    int frnt;
    int rear;
    int siz;
    int *Q;
public:
    Que(){
        frnt=rear=-1;
        siz = 10;
        Q = new int[siz];
    }
    Que(int siz){
        this->siz = siz;
        frnt=rear = -1;
        Q = new int[this->siz];
    }
    ~Que(){
        delete[] Q;
    }
    int enque(int val);
    int dequee();
    void display();



};

int Que :: enque(int val){
    if(rear==siz-1){
        cout<<"Que is full............."<<endl;
        return 0;
    }else{
        Q[++rear] = val;
        return 1;
    }
}
int Que :: dequee(){
    int x = -1;
    if(frnt==rear){
        cout<<"Que is full..............."<<endl;

    }else{
        frnt++;
        x = Q[frnt];
    }
    return x;
}
void Que :: display(){

    for(int i=frnt+1;i<=rear;i++){
        printf("%d ",Q[i]);
    }
}



int main(){

    Que ob;
    ob.enque(10);
    ob.enque(20);
    ob.enque(30);
    ob.dequee();

    ob.display();

    return 0;
}
