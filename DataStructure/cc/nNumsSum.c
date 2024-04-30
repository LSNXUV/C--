#include <stdio.h>
#include <math.h>
int nnum(int a, int n)
{
    if (n == 0)
    {
        return a;
    }
    else
    {
        return a * pow(10, n) + nnum(a, n - 1);
    }
}
int nsum(int a, int n)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        return nnum(a, n-1) + nsum(a, n - 1);
    }
}

int main()
{
    int n, a;
    scanf("%d", &a);
    scanf("%d", &n);
    printf("%d", nsum(a, n));
    scanf("%d", &a);
    
    return 0;
}