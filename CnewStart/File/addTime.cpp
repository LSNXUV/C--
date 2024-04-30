#include <iostream>
using namespace std;



int main(){
    int h,m,s;
    cin>>h>>m>>s;
    switch (s)
    {
    case 59 :
        s = 0;
        m++;
        break;
    default:
        s++;
        break;
    }
    switch (m)
    {
    case 60 :
        m = 0;
        h++;
        break;
    default:
        break;
    }
    switch (h)
    {
    case 24 :
        h = 0;
        break;
    default:
        break;
    }
    cout<<h<<":"<<m<<":"<<s<<endl;

    system("pause");
    return 0;
}