#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSortRecursive(int arr[], int start, int size) {
    // Base case: 如果数组只有一个元素，那么就已经排序好了
    if (start == size) return;

    bool swapped = false;
    // 把当前数组中的最大元素移动到末尾
    for (int j = 0; j < size - start - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            swapped = true;
        }
    }

    // 如果没有交换发生，那么数组已经排序完成，提前退出
    

    cout << "在第 " << start + 1 << " 次冒泡之后: ";
    printArray(arr, size);

    if (!swapped) return;
    // 在缩小的数组上递归地调用冒泡排序
    bubbleSortRecursive(arr, start + 1, size);
}


int main() {
    // int arr[] = {67,7,47, 37, 75, 72, 27, 17, 97};
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "初始序列: ";
    printArray(arr, size);
    bubbleSortRecursive(arr, 0, size);
    cout << "最终序列: ";
    printArray(arr, size);

    system("pause");
    return 0;
}
