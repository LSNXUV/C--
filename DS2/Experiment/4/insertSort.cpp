#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "在第 " << i << " 次插入之后: ";
        printArray(arr, size);
    }
}

int main() {
    int arr[] = {114,27,3,4,8,61,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "初始序列: ";
    printArray(arr, size);
    insertionSort(arr, size);
    cout << "最终序列: ";
    printArray(arr, size);
    system("pause");
    return 0;
}