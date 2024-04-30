#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a[1000] = {0};
    int x, z, flag = 0;
    while (1)
    {
        scanf("%d,%d", &x, &z);
        a[z] = a[z] + x;
        if (x == 0 && z == 0)
            break;
    }
    while (1)
    {
        scanf("%d,%d", &x, &z);
        a[z] = a[z] + x;
        if (x == 0 && z == 0)
            break;
    }

    for (int i = 0; i < 1000; i++)
    {
        if (a[i] != 0)
        {
            flag++;
            if (flag == 1)
                cout << a[i] << "x^" << i;
            else
                cout << "+" << a[i] << "x^" << i;
        }
    }
    system("pause");
}