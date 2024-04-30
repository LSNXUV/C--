#include <stdio.h>
#include <stdlib.h>



int main(){
    //输入 10 个数，按绝对值从大到小排序后输出。
    float a[10],t;
    int i,j;
    for(i=0;i<10;i++)
    {
        scanf("%f",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(abs(a[i]) < abs(a[j]))
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        if(i==9)
        {
            printf("%.2f",a[i]);
        }
        else
        {
            printf("%.2f,",a[i]);
        }
        
    }
    scanf("%f",&t);
return 0;
}
