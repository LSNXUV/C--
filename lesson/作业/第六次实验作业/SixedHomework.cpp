#include <iostream>
#include<iomanip>
#include<cmath>
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

double avrsalary(int rens){
    double salary[20];
    double all = 0;
    for(int i = 0;i < rens;i++)
    {
        cout<<"请输入第"<<i+1<<"个人的工资"<<endl;
        cin>>salary[i];
        all = all + salary[i];
        // cout<<all;
    }
    cout<<fixed<<setprecision(2)<<"平均工资为:"<<all/rens<<endl;
    return all/rens;
}
char* del(char word[20],int m,int n){
    strcpy(word+m-1,word+m+n-1);
    return word;
}

void out(){
    const int n = 8;
	int a[n][n];
	int i,j;
	for( i=0;i<=n-1;i++)
	{
		for( j=0;j<=i;j++)
		{
			if(j==0||j==i)
			{
				a[i][j]=1;
			}
			else 
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int Fibonacci(int n)
{
    if (n <= 0)    //基本情况
        return 0;
    else if (n == 1) // 基本情况
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
    char word[20];

    int m,n,rens,a,b,fib;

    
    cout<<"一、函数嵌套"<<endl;
    cout<<"请输入m和n(2<=m<n):";
    cin>>m>>n;
    Outprime(m,n);
    cout<<"二、指针与一维数组"<<endl;
    cout<<"请输入统计人数:";
    cin>>rens;
    avrsalary(rens);
    cout<<"三、指针与字符数组"<<endl;
    cout<<"请输入要操作的字符串:";
    cin>>word;
    cout<<"请输入删除的初识位置和结束位置的序号:";
    cin>>a>>b;
    cout<<"结果为:"<<del(word,a,b)<<endl;
    cout<<"四、二维数组"<<endl;
    cout<<"杨辉三角:"<<endl;
    out();
    cout<<"五、函数的递归"<<endl;
    cout<<"请输入非负数:"<<endl;
    cin>>fib;
    cout<<Fibonacci(fib);



    system("pause");
    return 0;
}