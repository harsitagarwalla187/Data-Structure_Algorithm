#include<bits/stdc++.h>

using namespace std;

void inplaceHeapSort(int arr[],int n) {

    for(int i=1;i<n;i++) {
        int cI = i;
        while(cI > 0) {
            int pI = (cI-1)/2;
            if(arr[cI] < arr[pI]) {
                int temp = arr[cI];
                arr[cI]  = arr[pI];
                arr[pI]  = temp;
            } else break;
            cI = pI;
        }
    }

    int size = n;

    while(size>1) {
        int temp = arr[0];
        arr[0]   = arr[size-1];
        arr[size-1] = temp;

        size--;

        int pI = 0;
        int LCI = 2*pI+1;
        int RCI = 2*pI+2;

        while(LCI < size) {
            int mI = pI;
            if(arr[mI]>arr[LCI]) mI = LCI;
            if(RCI < size && arr[mI]>arr[RCI]) mI = RCI;
            if(mI == pI) break;
            temp    = arr[pI];
            arr[pI] = arr[mI];
            arr[mI] = temp; 

            pI = mI;
            LCI = 2*pI+1;
            RCI = 2*pI+2;
        }
    }

}

int main() {

    int arr[]={5, 6, 8, 2};
    inplaceHeapSort(arr,4);
    for(int i=0;i<4;i++) cout<<arr[i]<<" ";
    cout<<"\n";   

    return 0;

}