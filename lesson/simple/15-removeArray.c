#include <stdio.h>



int main(){
    int a[100],n,m,i;
    scanf("%d %d",&n,&m);
    m = m%n;
    for(i=0;i<n;i++)
    {
        if (i<n-m)
        {
            scanf("%d",&a[i+m]);
        }
        else
        {
            scanf("%d",&a[i-n+m]);
        }
        
        
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    scanf("%d",&i);

return 0;
}