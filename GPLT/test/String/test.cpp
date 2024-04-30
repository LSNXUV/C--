#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s = "hello";
    // reverse(s.begin(),s.end());
    // sort(s.begin(),s.end());
    // rotate(s.begin(),s.begin()+2,s.end()); //
    unique(s.begin(),s.end()); //s = "helo"
    cout<<s<<endl;  //heloo, ÎªÊ²Ã´ÊÇheloo£¬
    system("pause");
    return 0;
}