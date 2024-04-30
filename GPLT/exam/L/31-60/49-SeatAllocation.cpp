#include <iostream>
using namespace std;
int main(){
    int n;                      //高校数量
    cin>>n;
    int *team = new int[n];     //记录n个高校的队伍数量，每队10人，最多10个队伍。
    int teamCount[11] = {0};    //记录队伍数量为i的高校数量，i：1-10。
    for(int i = 0;i<n;i++){
        cin>>team[i];
        teamCount[team[i]]++;   //记录队伍数量为i的高校，team[i]是1-10的整数
    }
    for(int i = 0;i<n;i++){     //直接按顺序输出n个高校的队员座位号
        cout<<"#"<<i+1<<endl;   //每个高校的第一行输出#i+1，因为i从0开始
        int step = max(2,n);    //step是座位号的增量，第一行的step必定是高校队伍的数量n，并且任何时候step都不能小于2，所以初始设置step为 max(2,n)
        for(int seat = i+1,count = 1;count <= team[i] * 10;count++,seat+=step){ //循环team[i] * 10次，输出座位号。count：当前第几个学生。seat：当前学生的座位号。
            cout<<seat<<(count % 10 == 0 ? "\n" : " "); //输出座位号，空格分隔，每10个换行。
            if(count % 10 == 0){                        //已经输出了一队（10人），调整step
                for(int k = 0;k < i;k++){               //查找已经输出了的（i之前的）高校
                    if(team[k] == count / 10){          //一找到一个刚好分配完毕（队伍数量 = 当前高校已输出的队伍数）的高校，
                        step --;                        //step就减1，因为已经有一个队伍分配完毕了，所以可以挤出1个位置分配了。
                    }
                }
            }
            if(count != 1 && count % 10 == 1){          //新的一行的第一个输出之后，调整step
                step = n;                               //step重新设置为n，方便计算新step
                for(int k = 1;k<=count / 10;k++){       //查找所有（高校队伍数量k <= 当前高校已经输出的队伍数量count / 10）的高校
                    if(teamCount[k] > 0){               //如果存在队伍数量为k的高校
                        step -= teamCount[k];           //step减去这些高校的数量，因为这些高校已经分配完了，所以可以挤出位置分配了。
                    }
                }
            }
            step = max(2,step);                         //再次声明，step不能小于2
        }
    }
    delete[] team;                                      //释放内存
    system("pause");                                 //方便调试
    return 0;
}