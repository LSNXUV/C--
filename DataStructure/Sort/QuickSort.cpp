#include <iostream>
using namespace std;

void QuickSot(int data[],int s,int t,int n,int &count)
{
    int i = s,j = t;
    int temp;

    if(s<t)
    {
        temp = data[s];
        while(i!=j)
        {
            while(j>i && data[j]>=temp) j--;

            data[i] = data[j];

            while(i<j && data[i]<=temp) i++;

            data[j] = data[i];
            
        }
        data[i] = temp;
        for(int i = 0;i<n;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
        count++;
        QuickSot(data,s,i-1,n,count);
        QuickSot(data,i+1,t,n,count);
    }
}


int main(){
    int data[500];
    int n=0,k,count = 0;
    while(cin>>k)
    {
        if(k == -1)
        {
            break;
        }
        data[n++] = k;
    }

    cout<<"排序前:";
    for(int i = 0;i<n;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;

    QuickSot(data,0,n-1,n,count);


    cout<<"排序后:";
    for(int i = 0;i<n;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<"count="<<count;

    system("pause");
    return 0;
}