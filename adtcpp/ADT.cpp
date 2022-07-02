#include <iostream>
#include <string>
using namespace std;

class Array{
    int size;
    int length;
    int *arr;

public:
    Array(){
        size = 10;
        length = 0;
        arr = new int[10];
    }
    Array(int size){
        this->size = size;
        length = 10;
        this->arr = new int[size];
    }
    ~Array(){
        delete []arr;
    }
    int push(int);
    int pop();
    int insertElement(int,int);
    int deletElement(int);
    void reverseArray();
    int linearSearch(int);
    int maxValue();
    int minValue();
    void sortArray();
    int bynarySearch(int);
    int replaceElement(int,int);
    void display();
};
void Array:: display(){
         for(int i=0;i<length-1;i++){
            cout<<arr[i]<<" , ";
         }
         cout<<arr[length-1]<<endl;
    }
int Array:: push(int element){
    this->arr[this->length] = element;
    this->length++;
    return element;
}
int Array:: pop(){
    int ele = arr[length];
    length--;
    return ele;
}
int Array:: insertElement(int index,int element){
    int i = this->length;
    while(index<i){
        arr[i] = arr[i-1];
        i--;
    }
    arr[i] = element;
    this->length++;
    return element;
}
int Array:: deletElement(int index){
    int i = index;
    int v = arr[index];
    while(i<length){
        arr[i] = arr[i+1];
        i++;
    }
    length--;
    return v;
}
void Array:: reverseArray(){
    int mid = length/2;
    int i,j,tem;
    for(i=0,j=length-1;i<mid;i++,j--){
        tem = arr[j];
        arr[j] = arr[i];
        arr[i] = tem;
    }

}
int Array:: linearSearch(int val){
    int i;
    for(i=0;i<length;i++){
        if(arr[i]==val){
            int tem;
            tem = arr[i];
            arr[i] = arr[0];
            arr[0] = tem;
            break;
        }
    }
    if(i==length){
        return 0;
    }else{
        return i+1;
    }
}
int Array :: maxValue(){
    int m = arr[0];
        int i;
        for(i=0;i<length;i++){
            if(arr[i]>m)
                m = arr[i];
        }
    return m;
}
int Array :: minValue(){
    int m = arr[0];
        int i;
        for(i=0;i<length;i++){
            if(arr[i]<m)
                m = arr[i];
        }
    return m;
}
void Array:: sortArray(){
    int i,ad;
    int len = this->length;
    while(len != 1){
        ad = 0;
        for(i=0;i<len-1;i++){
            int p;
            if(arr[i]>arr[i+1]){
                p = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = p;
                ad++;
                }
        }
        if(ad==0){
            break;
        }
        len--;
    }
}
int Array:: bynarySearch(int ele){
    sortArray();
    int low,heigh,mid;
    low = 0;
    heigh = length-1;
    mid = (low+heigh)/2;
    while(low<=heigh){

        if(arr[low]==ele || arr[heigh]==ele || arr[mid]==ele){
            int ind;
            ind = mid;
            (arr[low]==ele) ? ind = low : (arr[heigh]==ele) ? ind = heigh : printf("");

            return ind+1;
        }
        if(arr[mid]<ele){
            low = mid+1;
            heigh = heigh-1;
            mid = (low+heigh)/2;
        }else{
            low = low+1;
            heigh = mid -1;
            mid = (low+heigh)/2;
        }
    }
    return -1;

};
int Array::replaceElement(int index,int element){
    arr[index] = element;
    return element;
}

int main(){

    Array a;
    a.push(15);
    a.push(15);
    a.push(15);
    a.push(15);
    a.display();
    a.replaceElement(1,30);
    a.display();
    a.insertElement(2,100);
    a.display();
    a.reverseArray();
    a.display();
    a.push(1);
    a.display();
    cout<<a.linearSearch(1);
    cout<<a.bynarySearch(1);

    return 0;
}
