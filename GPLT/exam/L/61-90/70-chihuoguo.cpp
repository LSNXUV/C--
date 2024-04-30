#include<iostream>
#include<string>
using namespace std;
int main(){
    int n = 0,start = 0,cn = 0;
    string s;
    getline(cin,s);
    while(s != "."){
        n++;
        // for(int i = 0;i<s.length();i++){
        //     if(s.length()<14) break;
        //     if(s.substr(i,14).length() != 14) break;
        //     if(s.substr(i,14) == "chi1 huo3 guo1"){
        //         if(start == 0) start = n;
        //         cn++;
        //     }
        // }
        if(s.find("chi1 huo3 guo1") != string::npos){
            if(start == 0) start = n;
            cn++;
        }
        getline(cin,s);
    }
    cout<<n<<endl;
    if(start != 0){
        cout<<start<<" "<<cn;
    }else{
        cout<<"-_-#";
    }

    system("pause");
    return 0;
}
