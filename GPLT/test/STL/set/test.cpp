#include <iostream>
#include <set>
using namespace std;


int main(){
    int n = 4;
    set<int> s  = { 1,3,5,6,9};
    s.erase(*s.upper_bound(n)); // 替换大于n的最小值，这里删除大于n的最小值
    s.insert(n);            // 插入n
    for(auto i : s){
        cout << i << " ";
    }
    system("pause");
    return 0;
}