#include <iostream>
using namespace std;

/*
给定一个完全由小写英文字母组成的字符串等差递增序列，
该序列中的每个字符串的长度固定为 L，
从 L 个 a 开始，以 1 为步长递增。例如当 L 为 3 时，
序列为 { aaa, aab, aac, ..., aaz, aba, abb, ..., abz, ..., zzz }。
这个序列的倒数第27个字符串就是 zyz。
对于任意给定的 L，本题要求你给出对应序列倒数第 N 个字符串。
输入格式：
输入在一行中给出两个正整数 L（2 ≤ L ≤ 6）和 N（≤10 
5
 ）。

输出格式：
在一行中输出对应序列倒数第 N 个字符串。题目保证这个字符串是存在的。

输入样例：
3 7417
输出样例：
pat
*/

int pow(int a,int b){
    return b == 0 ? 1 : a * pow(a,b-1);
}

int main(){
    int n,m;
    cin>>n>>m;
    m -= 1;
    for(int i = n-1;i >= 0;i--){
        int p = pow(26,i);
        cout<<(char)(122 - m / p);
        m %= p;
    }
    system("pause");
    return 0;
}