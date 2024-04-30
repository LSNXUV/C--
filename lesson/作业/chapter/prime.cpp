#include <iostream>
using namespace std;


int main(){

    // for(int i = 2;i<1000;i++){
    //     for(int j = 1;j<i;j++){

    //         if(!i%j){
    //             break;
    //         }
    //         cout<<j<<"是质数";
    //     }


    // }
    int i,j;
    for(i=2; i<1000; i++) {
        for(j=2; j <= (i/j); j++) {
            if(!(i%j)) {
                break; // 如果找到，则不是质数
            }
        }
        if(j > (i/j)) {
            cout << i << " 是质数\n";
        }
    }
    



    system("pause");
    return 0;
}