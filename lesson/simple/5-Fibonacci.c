#include <stdio.h>

//输出第n个Fibonacci数
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    //输出第n个Fibonacci数
    int n;
    scanf("%d",&n);
    printf("%d",fibonacci(n));


return 0;
}
