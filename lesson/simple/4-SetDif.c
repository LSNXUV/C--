#include <stdio.h>
int main()
{
    int i, a;
    int A[1000] = {0};
    for (i = 0;; i++)
    {
        scanf("%d", &a);
        if (a == -1)
            break;
        A[i] = a;
    }
    int j, b;
    int B[1000] = {0};
    for (j = 0;; j++)
    {
        scanf("%d", &b);
        if (b == -1)
            break;
        B[j] = b;
    }
    int n, m;
    for (n = 0; n < i; n++)
    {
        for (m = 0; m < j; m++)
        {
            if (A[n] != B[m])
            {
                continue;
            }
            else
                break;
        }
        if (m == j)
            printf("%d ", A[n]);
    }
    return 0;
}
