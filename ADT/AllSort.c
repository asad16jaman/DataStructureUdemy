int b[100];
void Bubleshort(int *x,int len){
    int i,ad;
    while(len != 1){
        ad = 0;
        for(i=0;i<len-1;i++){
            int p;
            if(x[i]>x[i+1]){
                p = x[i];
                x[i] = x[i+1];
                x[i+1] = p;
                ad++;
                }
        }
        if(ad==0){
            break;
        }
        len--;
    }
}

void insertSort(int *ar,int len){
    int i;
    for(i=1;i<len;i++){
        int key = ar[i];
        int j = i-1;
        while(j >= 0 && ar[j]>key){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }

}

void selctionSort(int *arr,int siz){
    int val,ind,i,j,tem;
    for(int i=0;i<siz;i++){
            val = arr[i];
            ind = i;
            for(j=i;j<siz;j++){
                if(arr[j]<val){
                    val = arr[j];
                    ind = j;
                }
            }
            arr[ind] = arr[i];
            arr[i] = val;
    }
}
//Quick sort code bellow.............//
int parti(int *ar,int low,int hei){
    int piv = ar[low];
    int strt = low;
    int hi = hei;
    while(strt<hi){
        while(ar[strt]<=piv){
            strt++;
        }
        while(ar[hi]>piv){
            hi--;
        }
        if(strt<hi){
            int tem = ar[strt];
            ar[strt] = ar[hi];
            ar[hi] = tem;
        }
    }
    int tem = ar[hi];
    ar[hi] = ar[low];
    ar[low] = tem;
    return hi;
}

void QuickSort(int ar[],int low,int hei){
    if(low<hei){
        int mid = parti(ar,low,hei);
        QuickSort(ar,low,mid-1);
        QuickSort(ar,mid+1,hei);

    }
}
//marge Srot code bellow.....
void marge(int *A,int low,int mid,int high){
    int lb,ub,k;
    k = low;
    lb = low;
    ub = mid+1;
    while(lb<=mid && ub<=high){
        if(A[lb]<A[ub]){
            b[k++] = A[lb++];
        }else{
            b[k++] = A[ub++];
        }
    }
    while(lb<=mid){
        b[k++] = A[lb++];
    }

    while(ub<=high){
        b[k++] = A[ub++];

    }
    int i;
    for(i=low;i<=high;i++){
       A[i] = b[i];
    }
}
void margSort(int ar[],int low,int hei){
    int mid;
    if(low<hei){
        mid = (low+hei)/2;
        margSort(ar,low,mid);
        margSort(ar,mid+1,hei);
        marge(ar,low,mid,hei);
    }
}

