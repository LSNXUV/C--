#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSortRecursive(int arr[], int start, int size) {
    // 基本情况: 如果开始位置达到数组末尾，则返回
    if (start >= size - 1) return;

    // 寻找从开始位置到末尾的最小元素
    int minIndex = start;
    bool swapped = false;
    for (int j = start + 1; j < size; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }

    // 如果最小元素不在正确的位置，进行交换
    if (minIndex != start) {
        swap(arr[start], arr[minIndex]);
        swapped = true;
    }

    // 如果进行了交换，就输出排序进度
    if (swapped) {
        cout << "在第 " << start + 1 << " 次选择之后: ";
        printArray(arr, size);
    }

    // 在剩余的数组上递归调用选择排序
    selectionSortRecursive(arr, start + 1, size);
}

int main() {
    int arr[] = {114,27,3,4,8,61,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "初始序列: ";
    printArray(arr, size);
    selectionSortRecursive(arr, 0, size);
    cout << "最终序列: ";
    printArray(arr, size);
    system("pause");
    return 0;
}
