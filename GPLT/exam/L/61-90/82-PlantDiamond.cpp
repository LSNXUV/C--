/*
�����ʽ��
������һ���и�����ʯ�������� N�������� 10 
7
  ������������΢����Ϊ��λ�����˹�������ʯ���ٶ� v��1��v��200����΢����/��Ϊ��λ����������

�����ʽ��
��һ����������� N ΢������ʯ��Ҫ����������������һ���ʱ�䲻�����ڡ�

����������
102000 130
���������
784

*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(){
    int N, v;
    cin >> N >> v;
    cout << (int)ceil((double)N/v) << endl;

    system("pause");
    return 0;
}