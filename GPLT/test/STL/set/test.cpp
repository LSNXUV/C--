#include <iostream>
#include <set>
using namespace std;


int main(){
    int n = 4;
    set<int> s  = { 1,3,5,6,9};
    s.erase(*s.upper_bound(n)); // �滻����n����Сֵ������ɾ������n����Сֵ
    s.insert(n);            // ����n
    for(auto i : s){
        cout << i << " ";
    }
    system("pause");
    return 0;
}