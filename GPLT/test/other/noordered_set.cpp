#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;

    // ����Ԫ�ز����ֲ���˳��
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(2);

    // ���Ԫ��
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}