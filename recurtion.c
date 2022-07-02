#include <stdio.h>

int fun(int n,int a,int b,int c){

    if(n<=0){
        return 0;
    }
    fun(n-1,a,c,b);
    printf("(%d, %d)\n",a,c);
    fun(n-1,b,a,c);

}


int main(){
    fun(4,1,2,3);



    return 0;
}
