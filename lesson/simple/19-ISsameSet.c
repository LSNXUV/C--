#include <stdio.h>



int main(){
    //判断两个数组是否相同
    int a[50],b[50],i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]<=a[j]){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(b[i]<=b[j]){
                k=b[i];
                b[i]=b[j];
                b[j]=k;
            }
        }
    }
    for(i=0;i<n;i++){
        if(a[i]!=b[i]){
            printf("0");
            return 0;
        }
    }
    printf("1");


return 0;
}