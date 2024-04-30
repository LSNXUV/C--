#include <iostream>
#include <vector>
using namespace std;

// 递归函数，生成所有可能的组合
// start: 当前处理的数字
// n: 总共的数字范围
// combination: 当前已经选择的数字组合
void generateCombinations(int start, int n, vector<int>& combination) {
    // 如果当前数字已经超出范围，输出当前组合并返回
    if (start > n) {
        // 输出当前组合
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    
    // 包含当前数字
    combination.push_back(start); // 将当前数字加入组合
    generateCombinations(start + 1, n, combination); // 递归调用处理下一个数字
    combination.pop_back(); // 回溯，移除当前数字，以便尝试不包含当前数字的情况
    
    // 不包含当前数字
    generateCombinations(start + 1, n, combination); // 递归调用处理下一个数字
}

int main() {
    int n;
    cin >> n; // 输入总共的数字范围
    
    vector<int> combination; // 存储当前已经选择的数字组合
    generateCombinations(1, n, combination); // 从数字1开始生成所有可能的组合
    
    system("pause");
    return 0;
}
