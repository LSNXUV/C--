#include <iostream>
using namespace std;

void quicksort(int arr[],int size){
    if(size<=1) return; 
    int pivot=arr[size-1]; 
    int i=0,j=size-2;
    while(i<=j){
        while(arr[i]<pivot) i++; 
        while(j>=0 && arr[j]>pivot) j--; 
        if(i<j) swap(arr[i],arr[j]); 
        else break;
    }
    swap(arr[i],arr[size-1]); 
    quicksort(arr,i); 
    quicksort(arr+i+1,size-i-1); 

}

int main(){

    int arr[200];
    int n,i=0,k;
    cin>>k;
    while(cin.get() != '\n'){
        arr[i++]=k;
        cin>>k;
    }
    arr[i] = k;
    n = i;

    quicksort(arr,n);

    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    system("pause");
    return 0;
}