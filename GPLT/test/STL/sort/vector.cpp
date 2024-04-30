#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// �Զ���ıȽϺ��������յ�һ��Ԫ�صĽ�������
bool comparePair(const pair<string, string>& a, const pair<string, string>& b) {
    return a.first < b.first; // �����һ��Ԫ�ظ��󣬷��� true
}

int main() {
    vector<pair<string, string>> myVector;
    set<pair<string, string>,less<>> mySet;
    myVector.push_back(make_pair("00-00-30","00-00-40"));
    myVector.push_back(make_pair("00-00-10","00-00-20"));
    myVector.push_back(make_pair("00-00-20","00-00-30"));
    myVector.push_back(make_pair("00-00-10","00-00-30"));
    mySet.insert(make_pair("00-00-30","00-00-40"));
    mySet.insert(make_pair("00-00-10","00-00-50"));
    mySet.insert(make_pair("00-00-20","00-00-30"));
    mySet.insert(make_pair("00-00-10","00-00-30"));

    // ʹ���Զ���ıȽϺ����� vector ��������
    sort(myVector.begin(), myVector.end(), comparePair);
    cout<<"vector:"<<endl;
    for (const auto& pair : myVector) {
        cout << pair.first << ", " << pair.second << endl;
    }
    cout<<"set:"<<endl;
    for(const auto& pair : mySet) {
        cout << pair.first << ", " << pair.second << endl;
    }
    
    system("pause");
    return 0;
}
