#include <stdio.h>

void inser(int *ar,int len){
    int i,j,tem;
    for(i=1;i<len;i++){
        int key = ar[i];
        j = i-1;
        while(j>=0 && ar[j]>key){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }

}

void coinChange(int *ar,int n,int amount){
    int i=0,coin = 0,num;
    while(i<n){
        if(amount>=ar[i]){
            num = amount/ar[i];
            coin += num;
            amount = amount - (ar[i]*num);
        }
        i++;
    }
    if(amount == 0){
        printf("posible....");
    }else{
        printf("not possible....");
    }
}




int main(){


    int amount,n,i;
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    scanf("%d",&amount);
    inser(x,n);
    coinChange(x,n,amount);



return 0;

}
