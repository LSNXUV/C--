#include <iostream>

using namespace std;

// 顺序查找算法
int sequentialSearch(int arr[], int len, int target)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// 折半查找非递归算法
int binarySearchIterative(int arr[], int len, int target)
{
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

// 折半查找递归算法
int binarySearchRecursive(int arr[], int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    else
    {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}

int main()
{
    int testArray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int len = sizeof(testArray) / sizeof(testArray[0]);

    // 合法值测试
    int legalTarget = 11;
    cout << "合法值测试：\n" << "顺序查找结果: " << sequentialSearch(testArray, len, legalTarget) << endl;
    cout << "非递归折半查找结果: " << binarySearchIterative(testArray, len, legalTarget) << endl;
    cout << "递归折半查找结果: " << binarySearchRecursive(testArray, 0, len - 1, legalTarget) << endl<< endl;

    // 非法值测试
    int illegalTarget = 4;
    cout << "非法值测试：\n" << "顺序查找结果: " << sequentialSearch(testArray, len, illegalTarget) << endl;
    cout << "非递归折半查找结果: " << binarySearchIterative(testArray, len, illegalTarget) << endl;
    cout << "递归折半查找结果: " << binarySearchRecursive(testArray, 0, len - 1, illegalTarget) << endl<< endl;

    // 边界值测试
    int firstElem = testArray[0];
    int lastElem = testArray[len - 1];
    cout <<"边界值测试：\n" << "顺序查找结果 (第一个元素): " << sequentialSearch(testArray, len, firstElem) << endl;
    cout << "顺序查找结果 (最后一个元素): " << sequentialSearch(testArray, len, lastElem) << endl;
    cout << "非递归折半查找结果 (第一个元素): " << binarySearchIterative(testArray, len, firstElem) << endl;
    cout << "非递归折半查找结果 (最后一个元素): " << binarySearchIterative(testArray, len, lastElem) << endl;
    cout << "递归折半查找结果 (第一个元素): " << binarySearchRecursive(testArray, 0, len - 1, firstElem) << endl;
    cout << "递归折半查找结果 (最后一个元素): " << binarySearchRecursive(testArray, 0, len - 1, lastElem) << endl<< endl;

    system("pause");
    return 0;
}