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
    
    l.assign(v.begin(), v.end());   // ��v�е�Ԫ�ظ�ֵ��l
    l.unique();                     // ɾ�����������ظ�Ԫ��
    auto it = l.crbegin();        // ����һ�������������ָ�����һ��Ԫ��
    while(it != l.crend()){       // ����һ�������������ָ���һ��Ԫ�ص�ǰһ��λ��
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