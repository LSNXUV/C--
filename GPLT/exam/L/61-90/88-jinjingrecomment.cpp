#include<iostream>
using namespace std;
int a[1000];
int main()
{
    int n,k,grad,num=0;
    cin>>n>>k>>grad;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        if(x>=175)
        {
            if(y>=grad) num++;        //����Ĳ�������Ӱ��
            else if(a[x]<k)
            {
                a[x]++;
                num++;                //��ͨ��������Ӱ���
            }
        }
    }
    cout<<num;
    return 0;
 }