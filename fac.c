#include <stdio.h>

int fac(n){
    if(n>0){
        int x = fac(n-1)*n;
        return x;
    }
    return 1;
}
int mypow(b,p){
        if(p==0)
            return 1;
        return mypow(b,p-1)*b;
}


int fivonakki(int n){
    if(n<=1){
        return n;
    }
    return fivonakki(n-2) + fivonakki(n-1);
}


//it is febonakki but optimal recurtion fevonakkiii,,,,,,,
int ar[7] = {-1,-1,-1,-1,-1,-1,-1};
int fev(int n){
    if(n<=1){
        if(ar
           [n]==-1){
            ar[n] = n;
        }
        return ar[n];
    }else{
        if(ar[n-2]==-1){
            ar[n-2] = fev(n-2);
        }
        if(ar[n-1]==-1){
            ar[n-1] = fev(n-1);
        }
    }
    return ar[n-2]+ar[n-1];
}

//it is ncr problame.......
int NCR(int n,int r){
    if(n==r || r==0){
        return 1;
    }
    return NCR(n-1,r-1) + NCR(n-1,r);

}

void fff(int d,int a,int b,int c){

    if(d>0){

        fff(d-1,a,c,b);
        printf("(%d , %d) \n",a,c);
        fff(d-1,b,a,c);
    }
}




int main(){


    fff(3,1,2,3);


    return 0;

}
