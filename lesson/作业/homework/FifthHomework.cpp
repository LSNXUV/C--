#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool IsPrime(int n)
{
	if(n <= 1){
		// cout<<n<<"不是素数"<<endl; 
		return false;
	}
    for (int i = 2; i <sqrt(n); i++)
    {
        if ((n % i) == 0){
            // cout<<n<<"不是素数"<<endl;
            return false;
        }
    }
    cout<<n<<"是素数"<<endl;
    return true;
} 
void Outprime(int m,int n){
    for(int i = m;i<n;i++){
        IsPrime(i);
    }
}
void Outrepeat(char repeat[30],char ch){
    int j = 0;
    for(int i =1;i<strlen(repeat);i++){
        if(repeat[i]==ch){
            cout<<i<<"\t";
            j++;
        }
    }
    if(j==0){
        cout<<"NULL"<<endl;
    }
}
void Outdiagonal(){
    int arr[4][4];
    int sum = 0;
    cout<<endl<<"请输入16个数字:"<<endl;
    for(int i = 0;i < 4;i++){
        int j = 0;
        while(j < 4){
            // cout<<"请输入第"<<i+j-1<<"个数字:";
            cin>>arr[i][j];
            // cout<<i<<"\t"<<j<<endl;
            j++;
        }
    }
    sum = arr[1][1] + arr[2][2] + arr[3][3] + arr[0][0];
    cout<<"对角线和为:"<<sum<<endl;
}

typedef struct {
    int stunum;
    char name[10];
    int score[3];
}student;

student info[100];

void Outinf(int n){
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    for(int i = 0;i < n;i++){
        cout<<"请输入第"<<i+1<<"个学生信息(学号 姓名 英语 数学 计算机):"<<endl;
        cin>>info[i].stunum>>info[i].name>>info[i].score[1]>>info[i].score[2]>>info[i].score[3];
        
        sum1+=info[i].score[1];
        // cout<<sum1;
        if(max1<info[i].score[1]){
            max1 = info[i].score[1];
        }
       
        sum2+=info[i].score[2];
        if(max2<info[i].score[2]){
            max2 = info[i].score[2];
        }
        sum3+=info[i].score[3];
        if(max3<info[i].score[3]){
            max3 = info[i].score[3];
        }
    }
    cout<<"英语平均成绩为:"<<sum1/n<<"最高分为:"<<max1<<endl;
    cout<<"数学平均成绩为:"<<sum2/n<<"最高分为:"<<max2<<endl;
    cout<<"计算机平均成绩为:"<<sum3/n<<"最高分为:"<<max3<<endl;
}

int Fibonacci(int n) 
{
	if(n==0) 
		return 0;
	else if(n==1)
		return 1;
	else
		return Fibonacci(n-1)+Fibonacci(n-2);
}
int main(){
    int m,n,arr[4][4],students;
    int fib;
    char repeat[30],ch;
    cout<<"一、多重嵌套和循环中断"<<endl;
    cout<<"请输入m和n(2<=m<n):";
    cin>>m>>n;
    Outprime(m,n);
    cout<<"二、字符数组"<<endl;
    cout<<"请输入一串字符和单个字符（空格分开）:";
    cin>>repeat>>ch;
    Outrepeat(repeat,ch);
    cout<<"三、指针与一维数组"<<endl;
    cout<<"请输入一串字符和单个字符（空格分开）:";
    cin>>repeat>>ch;
    Outrepeat(repeat,ch);
    cout<<"四、二维数组"<<endl;
    Outdiagonal();
    cout<<"五、结构体的指针与数组"<<endl;
    cout<<"请输入要录入学生信息数:";
    cin>>students;
    Outinf(students);
    cout<<"六、函数的递归和嵌套"<<endl;
	cout<<"请输入一个数："<<endl;
	cin>>fib;
	cout<<Fibonacci(fib)<<endl;

    system("pause");
    return 0;
}