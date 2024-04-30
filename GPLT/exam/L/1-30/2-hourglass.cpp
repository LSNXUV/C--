#include<iostream>

using namespace std;

/*所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；
符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。
输入格式:
 1个正整数N（≤1000）和一个符号，中间以空格分隔。*/
int main(){
    int n;
    char c;
    cin >> n >> c;
    int i = 1;
    while (2 * i * i - 1 <= n) i++;
    i--;
    int j = 0;
    for (int k = i; k > 0; k--){
        for (int l = 0; l < j; l++) cout << " ";
        for (int l = 0; l < 2 * k - 1; l++) cout << c;
        cout << endl;
        j++;
    }
    j -= 2;     //这里-2是因为上面的j++多加了1次,并
    cout<<"j:"<<j<<endl;
    for (int k = 2; k <= i; k++){
        for (int l = 0; l < j; l++) cout << " ";
        for (int l = 0; l < 2 * k - 1; l++) cout << c;
        cout << endl;
        j--;
    }
    cout << n - 2 * i * i + 1 << endl;
    system("pause");
    return 0;
}