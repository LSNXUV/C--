#include<iostream>

using namespace std;

/*��ν��ɳ©��״������ָÿ��������������ţ����з������Ķ��룻�������з�������2��
�������ȴӴ�С˳��ݼ���1���ٴ�С����˳���������β��������ȡ�
�����ʽ:
 1��������N����1000����һ�����ţ��м��Կո�ָ���*/
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
    j -= 2;     //����-2����Ϊ�����j++�����1��,��
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