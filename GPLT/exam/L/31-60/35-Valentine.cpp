#include <iostream>
#include <set>
using namespace std;


int main(){
    int n = 0;
    string f,A,B;
    cin>>f;
    while(f != "." && n < 14){
        n++;
        if(n == 2){
            A = f;
        }else if(n == 14){
            B = f;
        }
        cin>>f;
    }
    if(n < 2){
        cout<<"Momo... No one is for you ..."<<endl;
    }else if(n < 14){
        cout<<A<<" is the only one for you..."<<endl;
    }else{
        cout<<A<<" and "<<B<<" are inviting you to dinner..."<<endl;
    }
    system("pause");
    return 0;
}