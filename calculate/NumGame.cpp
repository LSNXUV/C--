#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int X, k, N; // N=X^k
    while (cin >> N && N)
    {
        X = 0;
        k = 0;
        for (int i = 2; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                if ((int)pow(i,j) == N)
                {
                    X = i;
                    k = j;
                }
                if(pow(i, j) > N)
                    break;
            }
        }
        cout << X << " " << k << endl;
    }
    return 0;
}