#include <iostream>
using namespace std;
int main(){
    int n;                      //��У����
    cin>>n;
    int *team = new int[n];     //��¼n����У�Ķ���������ÿ��10�ˣ����10�����顣
    int teamCount[11] = {0};    //��¼��������Ϊi�ĸ�У������i��1-10��
    for(int i = 0;i<n;i++){
        cin>>team[i];
        teamCount[team[i]]++;   //��¼��������Ϊi�ĸ�У��team[i]��1-10������
    }
    for(int i = 0;i<n;i++){     //ֱ�Ӱ�˳�����n����У�Ķ�Ա��λ��
        cout<<"#"<<i+1<<endl;   //ÿ����У�ĵ�һ�����#i+1����Ϊi��0��ʼ
        int step = max(2,n);    //step����λ�ŵ���������һ�е�step�ض��Ǹ�У���������n�������κ�ʱ��step������С��2�����Գ�ʼ����stepΪ max(2,n)
        for(int seat = i+1,count = 1;count <= team[i] * 10;count++,seat+=step){ //ѭ��team[i] * 10�Σ������λ�š�count����ǰ�ڼ���ѧ����seat����ǰѧ������λ�š�
            cout<<seat<<(count % 10 == 0 ? "\n" : " "); //�����λ�ţ��ո�ָ���ÿ10�����С�
            if(count % 10 == 0){                        //�Ѿ������һ�ӣ�10�ˣ�������step
                for(int k = 0;k < i;k++){               //�����Ѿ�����˵ģ�i֮ǰ�ģ���У
                    if(team[k] == count / 10){          //һ�ҵ�һ���պ÷�����ϣ��������� = ��ǰ��У������Ķ��������ĸ�У��
                        step --;                        //step�ͼ�1����Ϊ�Ѿ���һ�������������ˣ����Կ��Լ���1��λ�÷����ˡ�
                    }
                }
            }
            if(count != 1 && count % 10 == 1){          //�µ�һ�еĵ�һ�����֮�󣬵���step
                step = n;                               //step��������Ϊn�����������step
                for(int k = 1;k<=count / 10;k++){       //�������У���У��������k <= ��ǰ��У�Ѿ�����Ķ�������count / 10���ĸ�У
                    if(teamCount[k] > 0){               //������ڶ�������Ϊk�ĸ�У
                        step -= teamCount[k];           //step��ȥ��Щ��У����������Ϊ��Щ��У�Ѿ��������ˣ����Կ��Լ���λ�÷����ˡ�
                    }
                }
            }
            step = max(2,step);                         //�ٴ�������step����С��2
        }
    }
    delete[] team;                                      //�ͷ��ڴ�
    system("pause");                                 //�������
    return 0;
}