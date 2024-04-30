#include <iostream>
#include <string>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    string result1 = "";
    string result2 = "";
    for(int i = 1;i<a.length();i++){
        if((a[i] - '0') % 2 == (a[i-1] - '0') % 2){
            result1 += to_string(max(a[i] - '0',a[i-1] - '0'));
        }
    }
    cout<<result1;
    for(int i = 1;i<b.length();i++){
        if((b[i] - '0') % 2 == (b[i-1] - '0') % 2){
            result2 += to_string(max(b[i] - '0',b[i-1] - '0'));
        }
    }
    if(result2 != result1)
        cout<<endl<<result2;
    system("pause");
    return 0;
}
