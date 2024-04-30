#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);


    list<int> l;
    l.push_front(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_front(7);
    
    l.assign(v.begin(), v.end());   // 将v中的元素赋值给l
    l.unique();                     // 删除所有相邻重复元素
    auto it = l.crbegin();        // 返回一个逆向迭代器，指向最后一个元素
    while(it != l.crend()){       // 返回一个逆向迭代器，指向第一个元素的前一个位置
        cout << *it << " ";
        it++;
    }
    
    /* auto it = l.rbegin();
    while(it != l.rend()){
        cout << *it << " ";
        it++;
    } */
    system("pause");
    return 0;
}