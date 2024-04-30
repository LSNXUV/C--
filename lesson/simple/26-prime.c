#include <stdio.h>

int Isprime(int n)
{
    int i;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main(){
    //输出范围内的素数之和
    int m,n,i,sum=0;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++)
    {
        if(Isprime(i))
        {
            sum+=i;
        }
    }
    printf("*%d-%d?*%d\n",m,n,sum);
    



    return 0;
}