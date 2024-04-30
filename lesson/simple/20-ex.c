#include <stdio.h>
#include <math.h>



int main()             
{
    int i;
    double x,n,f=1,p=1;
    scanf("%lf%lf",&x, & n);
    for (i = 1; i <= n; i++)
    {
        
        p *= i;
        f += pow((double)x,(double)i) / p;
    }
    printf("%.6lf", f);
    return 0;
}

