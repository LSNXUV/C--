#include <stdio.h>



int main(){
    //输出序列中间数,大于它的整数数量等于小于它的整数数量
    int a[1000],i,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(k=0;k<n;k++){
        // printf("%d \n",a[k]);
        int up = 0,down = 0;
        for(i=0;i<n;i++){
            if(a[i] < a[k]){
                down++;
            };
            if(a[i] > a[k]){
                up++;
            };

        }
        if(up == down && up != 0){
            printf("%d",a[k]);
            return 0;
        }
    }
    printf("-1");
    scanf("%d",&n);

    return 0;
}