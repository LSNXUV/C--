#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSortRecursive(int arr[], int start, int size) {
    // �������: �����ʼλ�ôﵽ����ĩβ���򷵻�
    if (start >= size - 1) return;

    // Ѱ�Ҵӿ�ʼλ�õ�ĩβ����СԪ��
    int minIndex = start;
    bool swapped = false;
    for (int j = start + 1; j < size; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }

    // �����СԪ�ز�����ȷ��λ�ã����н���
    if (minIndex != start) {
        swap(arr[start], arr[minIndex]);
        swapped = true;
    }

    // ��������˽�����������������
    if (swapped) {
        cout << "�ڵ� " << start + 1 << " ��ѡ��֮��: ";
        printArray(arr, size);
    }

    // ��ʣ��������ϵݹ����ѡ������
    selectionSortRecursive(arr, start + 1, size);
}

int main() {
    int arr[] = {114,27,3,4,8,61,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "��ʼ����: ";
    printArray(arr, size);
    selectionSortRecursive(arr, 0, size);
    cout << "��������: ";
    printArray(arr, size);
    system("pause");
    return 0;
}
