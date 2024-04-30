#include <iostream>
#include<iomanip>
using namespace std;

int main(){
    double salary[20];
    double all = 0;
    int rens;
    cin>>rens;
    for(int i = 0;i < rens;i++)
    {
        cin>>salary[i];
        all = all + salary[i];
    }
    cout<<all/rens<<endl;
    system("pause");
    return 0;
}