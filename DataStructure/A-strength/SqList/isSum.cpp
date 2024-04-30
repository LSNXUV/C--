#include <iostream>
using namespace std;

typedef struct
{
    int a[200];
    int length;
} sqList;

int main(){
    sqList Sq;
    cin>>Sq.length;
    int len = Sq.length;
    for(int i = 0;i<len;i++)
    {
        cin>>Sq.a[i];
    }
    int sum;
    cin>>sum;
    for(int i = 0;i<len;i++)
    {
        for(int j = i+1;j<len;j++)
        {
            if(Sq.a[i]+Sq.a[j]==sum)
            {
                cout<<"yes";
                return 0;
            }
        }
    }
    cout<<"no";

    system("pause");
    return 0;
}