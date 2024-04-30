#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int arr[] = {a, b, c};
    sort(arr, arr + 3);

    printf("%d->%d->%d\n", arr[0], arr[1], arr[2]);

    system("pause");
    return 0;
}
