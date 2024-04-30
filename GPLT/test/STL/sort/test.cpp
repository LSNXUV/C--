#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
int main() {
    vector<int> nums = {3, 1, 4, 5, 9, 2, 6, 7};

    // ʹ�� sort �� nums ���дӴ�С������
    sort(nums.begin(), nums.end()); //{1, 2, 3, 4, 5, 6, 7, 9}

    // ������
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;

    //test lower_bound, upper_bound
    auto it1 = lower_bound(nums.begin(), nums.end(), 5.5); //���ص�һ�����ڵ���5��Ԫ�صĵ�����
    auto it2 = upper_bound(nums.begin(), nums.end(), 5); //���ص�һ������5��Ԫ�صĵ�����
    cout << *it1 << " " << *it2 << endl;
    //�����greater<int>��һ���º�������������ʵ����С�ѣ������Ǵ�С���������Ĭ�������ѡ�
    priority_queue<int, vector<int>, less<int>> pq;
    for (const auto& num : nums) {
        pq.push(num);
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    system ("pause");
    return 0;
}
