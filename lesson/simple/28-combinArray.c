#include <stdio.h>



int main(){
    //合并两个数组为一个有序
    int a[50],b[50],c[100],i,j,k,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<m+n;i++)
    {
        if(i<n)
        {
            c[i]=a[i];
        }
        else
        {
            c[i]=b[i-n];
        }
    }
    for(i=0;i<m+n;i++)
    {
        for(j=i+1;j<m+n;j++)
        {
            if(c[i]>c[j])
            {
                k=c[i];
                c[i]=c[j];
                c[j]=k;
            }
        }
    }
    for(i=0;i<m+n;i++)
    {
        printf("%d ",c[i]);
    }


    return 0;
}