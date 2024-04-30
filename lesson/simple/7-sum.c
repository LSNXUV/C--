#include <stdio.h>



int main(){
    //计算整数各数字和
    int n;
    scanf("%d",&n);
    int sum = 0;
    while(n>0){
        sum = sum + n%10;
        n = n/10;
    }
    printf("%d",sum);

return 0;
}
