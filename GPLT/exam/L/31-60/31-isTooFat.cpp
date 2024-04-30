#include <iostream>
using namespace std;



int main(){
    int n;
    cin >> n;
    int h,w;
    for(int i=0;i<n;i++){
        cin >> h >> w;
        int standard = (h-100)*0.9*2;
        if(abs(w-standard)<standard*0.1){
            cout << "You are wan mei!" << endl;
        }else if(w>standard){
            cout << "You are tai pang le!" << endl;
        }else{
            cout << "You are tai shou le!" << endl;
        }
    }

    system("pause");
    return 0;
}