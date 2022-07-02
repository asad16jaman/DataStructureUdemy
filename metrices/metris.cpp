#include <iostream>

using namespace std;


class Metris{
    int *ar;
    int siz;

public:
   Metris(){
        siz = 5;
        ar = new int[siz];
   }

   Metris(int size){
    this->siz = size;
    this->ar = new int[size];
   }

   void setElement(int i,int j,int val){
        if(i==j){
            ar[i] = val;
        }
   }

   void display(){
        int i,j;
        for(i=0;i<siz;i++){
            for(j=0;j<siz;j++){
                if(i==j){
                    cout<<ar[i]<<" ";
                }else{
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
   }


};



int main(){

    Metris ob;
    ob.setElement(0,0,15);
    ob.setElement(1,1,15);
    ob.setElement(2,2,15);
    ob.setElement(3,3,15);
    ob.setElement(4,4,15);

    ob.display();

    return 0;
}
