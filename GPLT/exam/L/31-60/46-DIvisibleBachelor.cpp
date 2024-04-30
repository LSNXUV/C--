#include <iostream>
using namespace std;

/*
程序要读入一个整数x，这个整数一定是奇数并且不以5结尾。
然后，经过计算，输出两个数字：
第一个数字s，表示x乘以s是一个光棍，第二个数字n是这个光棍的位数。
*/

int main(){
    int n,count = 0,remainder = 0,start = false;
    cin>>n;
    while(true){
        remainder = remainder * 10 + 1; 
        if((remainder / n) != 0) start = true;
        if(start) cout<<(remainder / n);
        remainder = remainder % n;
        count++;
        if(remainder == 0) break;
    }
    cout<<" "<<count;
    system("pause");
    return 0;
}