#include <iostream>
#include <cstring>
using namespace std;

#define MaxSize 256

int *Add(char str1[], char str2[], int sum[])
{
    int x = 0, r = 0;
    int lena = strlen(str1);
    int lenb = strlen(str2);
    for (int i = lenb - 1, j = lena - 1; i >= 0; i--, j--)
    {
        x = (str1[j] - '0') + (str2[i] - '0');
        sum[j + 1] = (x + r) % 10;
        r = (x + r) / 10;
        if (i == 0)
        {
            sum[j] = r;
            break;
        }
        sum[j] = 0;
    }
    for (int i = lena - lenb; i > 0; i--)
    {
        x = str1[i - 1] - '0' + sum[i];
        sum[i] = x % 10;
        sum[i - 1] = x / 10;
    }
    return sum;
}

int main()
{

    char str1[MaxSize], str2[MaxSize];
    int sum[MaxSize] = {0};

    int lena, lenb;

    cin >> str1;
    cin >> str2;
    lena = strlen(str1);
    lenb = strlen(str2);

    if (lena > lenb)
    {
        Add(str1, str2, sum);
        int i = 0;
        while(sum[i]==0) i++;
        for(;i<=lena;i++)
        {
            cout<<sum[i];
        }
    }
    else
    {
        Add(str2, str1, sum);
        int i = 0;
        while(sum[i]==0) i++;
        for(;i<=lenb;i++)
        {
            cout<<sum[i];
        }
    }
    system("pause");
    return 0;
}