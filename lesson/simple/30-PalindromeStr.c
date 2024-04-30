#include <stdio.h>
#include <string.h>
// #include <windows.h>

int main()
{
    char c[100] = {0};
    int i = 0;
    int j;
    char ch;
    while ((ch = getchar()) != '#')
    {
        c[i++] = ch;
    }

    int len = strlen(c);
    

    int s = 0, l = len - 1;
    int k = 0;
    while (s < l)
    {
        if (c[s] != c[l])
        {
            k = 1;
            break;
        }
        s++;
        l--;
    }
    if (k == 0)
        printf("%d",len);
    else
        printf("no");

    // system("pause");
    return 0;
}