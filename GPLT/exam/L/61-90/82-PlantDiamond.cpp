/*
输入格式：
输入在一行中给出钻石的需求量 N（不超过 10 
7
  的正整数，以微克拉为单位）和人工培育钻石的速度 v（1≤v≤200，以微克拉/天为单位的整数）。

输出格式：
在一行中输出培育 N 微克拉钻石需要的整数天数。不到一天的时间不算在内。

输入样例：
102000 130
输出样例：
784

*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(){
    int N, v;
    cin >> N >> v;
    cout << (int)ceil((double)N/v) << endl;

    system("pause");
    return 0;
}