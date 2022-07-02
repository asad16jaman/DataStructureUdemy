#include <stdio.h>
#include <stdlib.h>
#include "AllSort.c"

struct Array{
    int size;
    int length;
    int *arr;
};
void display(struct Array ar){
    int i;
    for(i=0;i<ar.length;i++){
        printf("%d, ",ar.arr[i]);
    }
    printf("\n");
}
int push(struct Array *ar,int x){
    ar->arr[ar->length] = x;
    ar->length++;
    return x;
};
int pop(struct Array *ar){
    int x = ar->arr[ar->length];
    ar->length--;
    return x;
};
int set(struct Array *ar,int index,int val){
    int i = ar->length;
    while(index<i){
        ar->arr[i] = ar->arr[i-1];
        i--;
    }
    ar->arr[i] = val;
    ar->length++;
    return val;
}
int delet(struct Array *ar,int ind){
    int i = ind;
    int v = ar->arr[ind];
    while(i<ar->length){
        ar->arr[i] = ar->arr[i+1];
        i++;
    }
    ar->length--;
    return v;
}
int get(struct Array *ar,int index){
    return ar->arr[index];
}
void reverseArray(struct Array *ar){
    int mid = ar->length/2;
    int i,j,tem;
    for(i=0,j=ar->length-1;i<mid;i++,j--){
        tem = ar->arr[j];
        ar->arr[j] = ar->arr[i];
        ar->arr[i] = tem;
    }
}
int leanerSearch(struct Array *ar,int val){
    int i;
    for(i=0;i<ar->length;i++){
        if(ar->arr[i]==val){
            int tem;
            tem = ar->arr[i];
            ar->arr[i] = ar->arr[0];
            ar->arr[0] = tem;
            break;
        }
    }
    if(i==ar->length){
        return 0;
    }else{
        return i+1;
    }
}
int max(struct Array *ar){
    int m = ar->arr[0];
    if(ar->length>0){
        int i;
        for(i=0;i<ar->length;i++){
            if(ar->arr[i]>m)
                m = ar->arr[i];
        }
    }
    return m;
}
int min(struct Array *ar){
    int m = ar->arr[0];
    if(ar->length>0){
        int i;
        for(i=0;i<ar->length;i++){
            if(ar->arr[i]<m)
                m = ar->arr[i];
        }
    }
    return m;
}
int bynarySearch(struct Array *ar,int ele){
    Bubleshort(ar->arr,ar->length);
    int low,heigh,mid;
    low = 0;
    heigh = ar->length-1;
    mid = (low+heigh)/2;
    while(low<=heigh){

        if(ar->arr[low]==ele || ar->arr[heigh]==ele || ar->arr[mid]==ele){
            int ind;
            ind = mid;
            (ar->arr[low]==ele) ? ind = low : (ar->arr[heigh]==ele) ? ind = heigh : printf("");

            return ind+1;
        }
        if(ar->arr[mid]<ele){
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
}
