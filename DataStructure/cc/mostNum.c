#include <stdio.h>
// #include <windows.h>
int a[10001] = {0};
int main()
{
    int i = 0,n, k = 0, max = 0;
    scanf("%d",&n);
    while (i<n)
    {
        scanf("%d", &k);
        
        a[k]++;
        i++;
    }
    
    for (i = 0; i <= 10000; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        };
    }
    printf("%d", max); //输出max
    // system("pause");
    return 0;
}
