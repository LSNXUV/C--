#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

typedef struct
{
    int a[200];
    int length;
} sqList;

int main()
{
    sqList *sq, *sq1;
    sq  = (sqList *)malloc(sizeof(sqList));
    sq1 = (sqList *)malloc(sizeof(sqList));
    int m, n, i, j, k;
    cin >> sq->length >> sq1->length;
    m = sq->length;
    n = sq1->length;

    for (i = 0; i < m; i++)
    {
        cin >> sq->a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> sq1->a[i];
    }
    for (i = 0; i < m; i++)
    {
        cout<< sq->a[i] <<" ";
    }
    cout<<endl;
    for (i = 0; i < n; i++)
    {
        cout<< sq1->a[i] <<" ";
    }
    cout<<endl;


    for (i = 0; i < sq1->length; i++)
    {
        k = sq1->a[i],j = 0;
        while (j<sq->length && sq->a[j]!=k) j++;
        if(j == sq->length)
        {
            sq->a[sq->length] = k,sq->length++;
        }
    }

    
    for (i = 0; i < sq->length; i++)
    {
        cout<<sq->a[i]<<" ";
    }

    system("pause");
    return 0;
}