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
        cout << "在第 " << i + 1 << " 次冒泡之后: ";
        printArray(arr, size);
    }
}

int main() {
    // int arr[] = {67,7,47, 37, 75, 72, 27, 17, 97};
    int arr[] = {3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "初始序列: ";
    printArray(arr, size);
    bubbleSort(arr, size);
    cout << "最终序列: ";
    printArray(arr, size);

    system("pause");
    return 0;
}
