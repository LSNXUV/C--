#include <stdio.h>


// 给出一个不多于5位的正整数，要求：
// 1.求出它是几位数。
// 2.分别打印出每一位数字。
// 3.按照逆序打印出每一位数字。


int main(){
    int num,i,j;
    scanf("%d",&num);
    i=num;
    j=0;
    while(i>0)
    {
        i=i/10;
        j++;
    }
    printf("%d\n",j);
    printf("%d\n",num);
    i=num;
    while(i>0)
    {
        printf("%d",i%10);
        i=i/10;
    }

    

    


    
    

return 0;
}