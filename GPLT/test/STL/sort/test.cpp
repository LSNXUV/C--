#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
int main() {
    vector<int> nums = {3, 1, 4, 5, 9, 2, 6, 7};

    // 使用 sort 对 nums 进行从大到小的排序
    sort(nums.begin(), nums.end()); //{1, 2, 3, 4, 5, 6, 7, 9}

    // 输出结果
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;

    //test lower_bound, upper_bound
    auto it1 = lower_bound(nums.begin(), nums.end(), 5.5); //返回第一个大于等于5的元素的迭代器
    auto it2 = upper_bound(nums.begin(), nums.end(), 5); //返回第一个大于5的元素的迭代器
    cout << *it1 << " " << *it2 << endl;
    //这里的greater<int>是一个仿函数，可以用来实现最小堆，所以是从小到大输出。默认是最大堆。
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
