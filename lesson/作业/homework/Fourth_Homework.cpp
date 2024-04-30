#include <iostream>
using namespace std;

void newtime(){
    int h,m,s;
    cout<<"请分别输入 时 分 秒(空格分开):"<<endl;
    cin>>h>>m>>s;
    switch (s)
    {
    case 59 :
        s = 0;
        m++;
        break;
    default:
        s++;
        break;
    }
    switch (m)
    {
    case 60 :
        m = 0;
        h++;
        break;
    default:
        break;
    }
    switch (h)
    {
    case 24 :
        h = 0;
        break;
    default:
        break;
    }
    cout<<"时间为:"<<h<<":"<<m<<":"<<s<<endl;
}

int InvertSequence(int num){
    
    int result = 0;
	// 将整数倒序
	for (int i = num; i ; )
	{
		// 去掉个位上的数
		i = i/10*10;
		// 将result进一位，并加上当前个位上的数（num-i）
		result = result * 10 + num - i;
 
		i = i /10;
		num = num/10;
	}
    return result;
}
float sum(float a,float b){
    float *c,*d;
    c = &a;
    d = &b;
    return *c+*d;
}
float product(float a,float b){
    float *c,*d;
    c = &a;
    d = &b;
    return *c**d;
}

int main(){
    int num;
    float a,b;
    cout<<"一.多分支结构"<<endl<<"1.1"<<endl;
    newtime();
    cout<<"二.函数"<<endl<<"2.1"<<endl;
    cout<<"请输入正整数:"<<endl;
    cin>>num;
    cout<<"逆序数为:"<<InvertSequence(num)<<endl;
    cout<<"三.指针"<<endl<<"3.1"<<endl;
    cout<<"请输入两个数:"<<endl;
    cin>>a>>b;
    cout<<"和:"<<sum(a,b)<<endl<<"积:"<<product(a,b);
    system("pause");
    return 0;
}