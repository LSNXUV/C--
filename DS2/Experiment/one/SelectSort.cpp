#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        cout << "在第 " << i + 1 << " 次选择之后: ";
        printArray(arr, size);
    }
}

int main() {
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "初始序列: ";
    printArray(arr, size);
    selectionSort(arr, size);
    cout << "最终序列: ";
    printArray(arr, size);
    system("pause");
    return 0;
}
