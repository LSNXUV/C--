#include <iostream>
#include <vector>
using namespace std;

// �ݹ麯�����������п��ܵ����
// start: ��ǰ���������
// n: �ܹ������ַ�Χ
// combination: ��ǰ�Ѿ�ѡ����������
void generateCombinations(int start, int n, vector<int>& combination) {
    // �����ǰ�����Ѿ�������Χ�������ǰ��ϲ�����
    if (start > n) {
        // �����ǰ���
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    
    // ������ǰ����
    combination.push_back(start); // ����ǰ���ּ������
    generateCombinations(start + 1, n, combination); // �ݹ���ô�����һ������
    combination.pop_back(); // ���ݣ��Ƴ���ǰ���֣��Ա㳢�Բ�������ǰ���ֵ����
    
    // ��������ǰ����
    generateCombinations(start + 1, n, combination); // �ݹ���ô�����һ������
}

int main() {
    int n;
    cin >> n; // �����ܹ������ַ�Χ
    
    vector<int> combination; // �洢��ǰ�Ѿ�ѡ����������
    generateCombinations(1, n, combination); // ������1��ʼ�������п��ܵ����
    
    system("pause");
    return 0;
}
