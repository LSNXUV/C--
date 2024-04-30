#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped) {
            cout <<endl<< "�� " << i + 1 << " ���������: ";
            printArray(arr, n);
        } else {
            break;
        }
    }
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "��ʼ���У�" ;
    printArray(arr, n);cout<<endl;
    bubbleSort(arr, n);
    cout <<endl<< "�������У�" ;
    printArray(arr, n);cout<<endl;
    system("pause");
    return 0;
}

