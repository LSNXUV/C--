#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int maxLength = 0;
    int n = str.length();
    for (int i = 0; i < n; i++) {   // ��iΪ����, ��������չ, ����Գ��Ӵ�
        for (int j = 0; i - j >= 0 && i + j < n && str[i - j] == str[i + j]; j++) { // ��������
            maxLength = max(maxLength, 2 * j + 1);
        }
        for (int j = 0; i - j >= 0 && i + 1 + j < n && str[i - j] == str[i + 1 + j]; j++) { // ż������
            maxLength = max(maxLength, 2 * j + 2);
        }
    }
    cout << maxLength << endl;
    return 0;
}
