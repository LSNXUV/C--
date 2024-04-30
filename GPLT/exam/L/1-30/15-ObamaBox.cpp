#include <iostream>
using namespace std;



int main(){
    int n;
    char c;
    cin>>n>>c;
    //ËÄÉáÎåÈë
    int rows = n/2 + n%2; 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < n; j++){
            cout<<c;
        }
        cout<<endl;
    }


    system("pause");
    return 0;
}