#include <iostream>
using namespace std;


void Sift(int arr[],int low,int high)
{
    int i = low,j = 2 * i;
    int temp = arr[i];
    while(j<=high)
    {
        if(j<high && arr[j] < arr[j+1]) j++;
        if(temp < arr[j])
        {
            arr[i] = arr[j];
            i = j;
            j = 2*i;
        }
        else break;
    }
    arr[i] = temp;
}

void HeapSort(int arr[],int n)
{
    int i;
    int temp;
    for(i = n/2;i>=1;i--){
        Sift(arr,i,n);
        
    }
    cout<<"初始堆:";
    for(int i = 1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(i = n;i>=2;i--)
    {
        temp = arr[1];
        arr[1] = arr[i]; 
        arr[i] = temp;

        cout<<"第"<<n-i+1<<"趟:";
        for(int i = 1;i<=n;i++)
        {
            cout<<" "<<arr[i];
        }
        cout<<endl;
        
        Sift(arr,1,i-1);

        cout<<"筛选为:";
        for(int i = 1;i<=n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[500],k,n = 1;

    while(cin>>k)
    {
        if(k == -1) break;
        arr[n++] = k;
    }
    n--;

    cout<<"排序前:";
    for(int i = 1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    HeapSort(arr,n);

    cout<<"排序后:";
    for(int i = 1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
