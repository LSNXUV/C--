#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int maxLength = 0;
    int n = str.length();
    for (int i = 0; i < n; i++) {   // 以i为中心, 向两边扩展, 求最长对称子串
        for (int j = 0; i - j >= 0 && i + j < n && str[i - j] == str[i + j]; j++) { // 奇数长度
            maxLength = max(maxLength, 2 * j + 1);
        }
        for (int j = 0; i - j >= 0 && i + 1 + j < n && str[i - j] == str[i + 1 + j]; j++) { // 偶数长度
            maxLength = max(maxLength, 2 * j + 2);
        }
    }
    cout << maxLength << endl;
    return 0;
}
