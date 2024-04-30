#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSortRecursive(int arr[], int start, int size) {
    // Base case: �������ֻ��һ��Ԫ�أ���ô���Ѿ��������
    if (start == size) return;

    bool swapped = false;
    // �ѵ�ǰ�����е����Ԫ���ƶ���ĩβ
    for (int j = 0; j < size - start - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            swapped = true;
        }
    }

    // ���û�н�����������ô�����Ѿ�������ɣ���ǰ�˳�
    

    cout << "�ڵ� " << start + 1 << " ��ð��֮��: ";
    printArray(arr, size);

    if (!swapped) return;
    // ����С�������ϵݹ�ص���ð������
    bubbleSortRecursive(arr, start + 1, size);
}


int main() {
    // int arr[] = {67,7,47, 37, 75, 72, 27, 17, 97};
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "��ʼ����: ";
    printArray(arr, size);
    bubbleSortRecursive(arr, 0, size);
    cout << "��������: ";
    printArray(arr, size);

    system("pause");
    return 0;
}
