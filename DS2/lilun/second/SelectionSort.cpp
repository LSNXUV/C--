#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        cout << "i: " << i << ", j: " << minIndex << ", ����Ԫ��: " << arr[i] << " �� " 
        << arr[minIndex] << endl<<"���У�";
        printArray(arr, n);cout<<endl;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 77, 55 ,159, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "��ʼ���У�" ;
    printArray(arr, n);cout<<endl;
    selectionSort(arr, n);
    cout << "�������У�" ;
    printArray(arr, n);cout<<endl;
    system("pause");
    return 0;
}

