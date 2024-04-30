#include <iostream>

using namespace std;

// ˳������㷨
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

// �۰���ҷǵݹ��㷨
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

// �۰���ҵݹ��㷨
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

    // �Ϸ�ֵ����
    int legalTarget = 11;
    cout << "�Ϸ�ֵ���ԣ�\n" << "˳����ҽ��: " << sequentialSearch(testArray, len, legalTarget) << endl;
    cout << "�ǵݹ��۰���ҽ��: " << binarySearchIterative(testArray, len, legalTarget) << endl;
    cout << "�ݹ��۰���ҽ��: " << binarySearchRecursive(testArray, 0, len - 1, legalTarget) << endl<< endl;

    // �Ƿ�ֵ����
    int illegalTarget = 4;
    cout << "�Ƿ�ֵ���ԣ�\n" << "˳����ҽ��: " << sequentialSearch(testArray, len, illegalTarget) << endl;
    cout << "�ǵݹ��۰���ҽ��: " << binarySearchIterative(testArray, len, illegalTarget) << endl;
    cout << "�ݹ��۰���ҽ��: " << binarySearchRecursive(testArray, 0, len - 1, illegalTarget) << endl<< endl;

    // �߽�ֵ����
    int firstElem = testArray[0];
    int lastElem = testArray[len - 1];
    cout <<"�߽�ֵ���ԣ�\n" << "˳����ҽ�� (��һ��Ԫ��): " << sequentialSearch(testArray, len, firstElem) << endl;
    cout << "˳����ҽ�� (���һ��Ԫ��): " << sequentialSearch(testArray, len, lastElem) << endl;
    cout << "�ǵݹ��۰���ҽ�� (��һ��Ԫ��): " << binarySearchIterative(testArray, len, firstElem) << endl;
    cout << "�ǵݹ��۰���ҽ�� (���һ��Ԫ��): " << binarySearchIterative(testArray, len, lastElem) << endl;
    cout << "�ݹ��۰���ҽ�� (��һ��Ԫ��): " << binarySearchRecursive(testArray, 0, len - 1, firstElem) << endl;
    cout << "�ݹ��۰���ҽ�� (���һ��Ԫ��): " << binarySearchRecursive(testArray, 0, len - 1, lastElem) << endl<< endl;

    system("pause");
    return 0;
}