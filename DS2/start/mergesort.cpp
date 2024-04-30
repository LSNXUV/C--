// First, we need to take input from the user for the length of the array and its elements
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int& count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[200], R[200];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        count++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int& count) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);

        merge(arr, l, m, r, count);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[200];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // cout << endl;
    cout <<"count:"<<endl<< count << endl;

    system("pause");
    return 0;
} 

// The above code takes input from the user for the length of the array and its elements, 
// sorts the array using merge sort algorithm and outputs the sorted array and the number of comparisons made.