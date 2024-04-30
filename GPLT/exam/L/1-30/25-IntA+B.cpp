#include <iostream>
#include <string>
using namespace std;

/*
其中A和B都在区间[1,1000]
输入格式：
输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

输出格式：
如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，则在相应位置输出?，显然此时和也是?。

输入样例1：
123 456
输出样例1：
123 + 456 = 579
输入样例2：
22. 18
输出样例2：
? + 18 = ?
输入样例3：
-100 blabla bla...33
输出样例3：
? + ? = ?
*/

bool isInt(string s){
    if(s[0] == '0' || s.length() > 4){
        return false;
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] < '0' || s[i] > '9'){
            return false;
        }
    }
    if(stoi(s) > 1000){
        return false;
    }
    return true;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(!isInt(a)){
        a = "?";
    }
    if(!isInt(b)){
        b = "?";
    }
    cout << a << " + " << b << " = ";
    string result = "?";
    if(a != "?" && b != "?"){
        result = to_string(stoi(a) + stoi(b));
    }
    cout << result;
    
    system("pause");
    return 0;
}