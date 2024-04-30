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
    int m, n, i, j, k,l = 0;
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
    // for (i = 0; i < m; i++)
    // {
    //     cout<< sq->a[i] <<" ";
    // }
    // cout<<endl;
    // for (i = 0; i < n; i++)
    // {
    //     cout<< sq1->a[i] <<" ";
    // }
    // cout<<endl;


    for (i = 0; i < sq->length; i++)
    {
        k = sq->a[i],j = 0;
        while (j<sq1->length && sq1->a[j]!=k) j++;
        if(j == sq1->length){
            continue;
        }
        cout<<sq1->a[j]<<" ",l++;
    }
    if(l == 0){
        cout<<"The intersection is empty";
    }

    system("pause");
    return 0;
}