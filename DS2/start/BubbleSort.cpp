#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n; // 先输入数组长度
    int a[500];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // 依次输入数据，空格分隔
    }

    int cnt = 0;                            // 初始化比较次数
    bool flag = true;                       // 初始化标志变量
    for (int i = 0; i < n - 1 && flag; i++) // 外层循环
    {
        flag = false;                       // 每次循环开始前，将标志变量置为false
        for (int j = 0; j < n - i - 1; j++) // 内层循环
        {
            cnt++;               // 统计比较次数
            if (a[j] > a[j + 1]) // 如果前一个数大于后一个数
            {
                swap(a[j], a[j + 1]); // 交换两个数
                flag = true;          // 如果有数据交换，则将标志变量置为true
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; // 输出排序后的数组
    }
    cout << endl
         << cnt << endl; // 输出比较次数

    system("pause");
    return 0;
}