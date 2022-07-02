#include <stdio.h>
#include <stdbool.h>

int main(){
    /*
    char arr[] = "finding";
    int h = 0, x = 0,i;
    for(int i=0; arr[i] != '\0'; i++){
        x=1;
        x = x<<(arr[i]-97);
        if(x&h){
            printf("duplicate....%c\n",arr[i]);
        }else{
            h = x|h;
        }
    }
    */

    int rep[30] = {0};
    char ar[] = "hellow world i am bangladeshi";
    int i;
    for(i=0;ar[i]!='\0';i++){
        if(ar[i]>=97 && ar[i]<=122){
            rep[ar[i]-97] = rep[ar[i]-97] + 1;
        }
    }
    int x;
    int s,ind;
    s = ind = 0;
    for(x=0;x<30;x++){
        if(rep[x]>s){
            s = rep[x];
            ind = x;
        }
    }
    printf("%c......use is %d",ind+97,s);

    return 0;
}
