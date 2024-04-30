#include <iostream>
using namespace std;

#define Max 200

typedef struct
{
    int i, j;
    int data;
} Triple;

typedef struct
{
    Triple data[Max];
    int mu, nu, tu;
} TMatrix;

void Create(TMatrix &M, int Mr[][4])
{
    M.tu = 0;
    M.mu = 4;
    M.nu = 4;
    int i, j;
    for (i = 0; i < M.mu; i++)
    {
        for (j = 0; j < M.nu; j++)
        {
            cin >> Mr[i][j];
            if (Mr[i][j] != 0)
            {
                M.data[M.tu].i = i;
                M.data[M.tu].j = j;
                M.data[M.tu++].data = Mr[i][j];
            }
        }
    }
}

TMatrix CombMatrix(int Mar[][4], int Mbr[][4])
{
    TMatrix T;
    T.mu = 4;
    T.nu = 4;
    T.tu = 0;
    for(int i = 0;i<T.mu;i++)
    {
        for(int j = 0;j<T.nu;j++)
        {
            if(Mar[i][j] != 0 || Mbr[i][j] != 0)
            {
                T.data[T.tu].i = i;
                T.data[T.tu].j = j;
                T.data[T.tu++].data = Mar[i][j] + Mbr[i][j];
            }
        }
    }

    return T;
}

void DisPlay(TMatrix M)
{
    cout << "   " << M.mu << "   " << M.nu << "   " << M.tu << endl;
    cout << "------------" << endl;
    for (int i = 0; i < M.tu; i++)
    {
        if(M.data[i].data >= 10){
            cout << "   " << M.data[i].i << "   " << M.data[i].j << "  " << M.data[i].data << endl;
        }
        else if(M.data[i].data < 0){
            cout << "   " << M.data[i].i << "   " << M.data[i].j << " " << M.data[i].data << endl;
        }
        else{
            cout << "   " << M.data[i].i << "   " << M.data[i].j << "   " << M.data[i].data << endl;
        }
        
    }
}

int main()
{
    int Mar[4][4], Mbr[4][4];

    TMatrix Ma, Mb, CbM;
    cout << "input matrix a:" << endl;
    Create(Ma, Mar);
    cout << "input matrix b:" << endl;
    Create(Mb, Mbr);

    cout << "The triple a:" <<endl;
    DisPlay(Ma);

    cout << "The triple b:" << endl;
    DisPlay(Mb);

    cout << "c=a+b" << endl;
    CbM = CombMatrix(Mar,Mbr);
    cout << "The triple c:" << endl;
    DisPlay(CbM);

    return 0;
}
