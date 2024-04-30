#include <iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n/4+1;i++)
        {
            for(int j=0;j<=n/3+1;j++)
            {
                if(i*4+j*3+(n-i-j)*0.5==n)
                {
                    cout<<i<<" "<<j<<" "<<n - i - j<<endl;
                }
            }
        }
    system("pause");
    return 0;
}