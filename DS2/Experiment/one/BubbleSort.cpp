#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        cout << "�ڵ� " << i + 1 << " ��ð��֮��: ";
        printArray(arr, size);
    }
}

int main() {
    // int arr[] = {67,7,47, 37, 75, 72, 27, 17, 97};
    int arr[] = {3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "��ʼ����: ";
    printArray(arr, size);
    bubbleSort(arr, size);
    cout << "��������: ";
    printArray(arr, size);

    system("pause");
    return 0;
}
