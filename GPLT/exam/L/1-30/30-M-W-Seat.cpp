#include <iostream>
using namespace std;

/*
��ʦ��ѧϰ�ɼ���ǰ��ѧ����ѧϰ�ɼ������ѧ������һ�顣����������д���������ʦ�Զ����������乤�������ڵõ�ȫ��ѧ�����������ڵ�ǰ��δ�����ѧ���У��������ǰ��ѧ����������������ѧ����Ϊһ�顣

�����ʽ��
�����һ�и�����ż��N����50������ȫ��ѧ�����������˺�N�У��������δӸߵ��͵�˳�����ÿ��ѧ�����Ա�0����Ů����1������������������������8��Ӣ����ĸ�ķǿ��ַ������������1���ո�ָ������ﱣ֤������Ů������1:1������û�в������Ρ�

�����ʽ��
ÿ�����һ������ѧ���������������1���ո�ָ������θߵ�ѧ����ǰ�����ε͵�ѧ���ں�С������˳����ǰ��ѧ�������δӸߵ������С�

����������
8
0 Amy
1 Tom
1 Bill
0 Cindy
0 Maya
1 John
1 Jack
0 Linda
���������
Amy Jack
Tom Linda
Bill Maya
Cindy John
*/

int main(){
    int n;
    cin>>n;

    int *sex = new int[n];
    string *name = new string[n];

    for(int i = 0;i<n;i++){
        cin>>sex[i]>>name[i];
    }

    int start = 0,end1 = n-1, end2 = n-1;

    while(sex[end2] == sex[end1]) end2--;
    while(start < n/2){
        if(sex[start] != sex[end1]){
            cout<<name[start]<<" "<<name[end1]<<endl;
            int curSex = sex[end1--];
            while(end1 >= n/2 && sex[end1] != curSex) end1--;
        }else{
            cout<<name[start]<<" "<<name[end2]<<endl;
            int curSex = sex[end2--];
            while(end2 >= n/2 && sex[end2] != curSex) end2--;
        }
        start++;
    }

    system("pause");
    return 0;
}