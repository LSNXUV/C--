#include <stdio.h>

int getMax(int a[], int n)
{
    int i;
    if (a == NULL || n < 2)
    {

        return 0;
    }
    int max = a[0];
    int maxDiff = max - a[1];

    for (i = 2; i < n; i++)
    {

        if (a[i - 1] > max)
        {
            max = a[i - 1];
        }
        int currentDiff = max - a[i];
        if (currentDiff > maxDiff)
        {
            maxDiff = currentDiff;
        }
    }

    return maxDiff;
}

int main()
{

    // int i;
    int n = 0, k;
    int a[100];
    char ch;
    do
    {
        scanf("%d", &k);
        a[n++] = k;

    } while ((ch = getchar()) != EOF);

    // for(i = 0;i<n;i++){
    //     printf("%d",a[i]);
    // }
    int max = -100,i,j;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (a[i] - a[j] > max)
            {
                max = a[i] - a[j];
            }
        }
    }

    printf("%d", max);

    scanf("%d", &n);
    return 0;
}