
#include <iostream>

void reverseArr(int *arr, int n)
{
    int i, j, temp;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    int n,i;
    int arr[100];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    reverseArr(arr, n);
    printf("*");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }   
    system("pause");
    return 0;
}
