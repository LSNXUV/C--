#include <stdio.h>


int arr[10017];
int cent[50];

int main()
{
    int i,j;
    int n,m;
    
    scanf("%d%d",&n,&m);

    for(i = 1;i<=n;i++){
        scanf("%d",&cent[i]);
    }

    arr[0] = 1;
    for(i = 1;i<=n;i++){

        for(j = cent[i];j<=m;j++){
            // printf("%d\n",arr[j]);
            arr[j] += arr[j - cent[i]];
        }
    }
    printf("%d\n",arr[m]);
    scanf("%d",&n);

    return 0;
}