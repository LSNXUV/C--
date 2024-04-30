#include <iostream>

#include<iomanip>
using namespace std;

void ShellSort(int data[],int n,int Darr[],int Dnum)
{
    int i,j,d;
    int dnum = 0;
    int temp;

    d = Darr[dnum];
    while(dnum++<Dnum)
    {

        for(i = d;i<n;i++)
        {
            temp = data[i];
            j = i-d;
            while(j>=0 && temp < data[j])
            {
                data[j+d] = data[j];
                j = j-d;

            }
            data[j+d] = temp;
        }
        d = Darr[dnum];

        /* for(int i = 0;i<n;i++)
        {
            cout<<std::right<<setw(4)<<data[i];
        }
        cout<<endl; */
        
    }

}

int main(){
    int data[500];
    int n=0,k;
    int Darr[50];
    int Dnum;
    cin>>Dnum;
    for(int i = 0;i<Dnum;i++)
    {
        cin>>Darr[i];
    }
    while(cin>>k)
    {
        if(k == -1)
        {
            break;
        }
        data[n++] = k;
    }

    cout<<"the resource datas is:"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<std::right<<setw(4)<<data[i];
    }
    cout<<endl;

    cout<<"every shellinsert px result is\n"<<endl;

    ShellSort(data,n,Darr,Dnum);


    cout<<"the shellinsert result datas is:\n"<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<std::right<<setw(4)<<data[i];
    }


    // system("pause");
    return 0;
}

