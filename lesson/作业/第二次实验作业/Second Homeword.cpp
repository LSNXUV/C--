#include <iostream>
#include <string>
#include <cstring>
using namespace std;

double max(double a,double b){

    return a > b ? a : b;
}
int reverseint(int num){
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
char* dopoem(){
    static char poem[88];
    strcpy(poem,"夜雨寄北\n唐·李商隐\n君问归期未有期，\n巴山夜雨涨秋池。\n何当共剪西窗烛，\n却话巴山夜雨时。");
    return poem;
}
char* Isleap(int year){
    static char isleap[70];
    static char isnotleap[70];
    strcpy(isleap,"Yes");
    strcpy(isnotleap," No");
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ){
	    return isleap;
    } return isnotleap;
}
float* min(float arr[],int n){
    float min = arr[0];
    float index = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
            index = i;
        }
    }
    static float arr1[2];
    arr1[0] = min;
    
    arr1[1] = index;
    return arr1;
}

int main(){
    double a,b,c,d;
    int i,year,n;
    float farr[10];
    cout<<"一.选择结构"<<endl;
    cout<<"请输入四个双精度浮点数以比较大小:";
    cin>>a>>b>>c>>d;
    cout<<"最大数为"<<max(max(max(a,b),c),d)<<endl;
    cout<<"二.循环结构"<<endl;
    
    cout<<"请输入要逆转的正整数:"; 
    cin>>i;
    while (i<0)
    {
        cout<<"请输入正整数:";
        cin>>i;
    }
    cout<<"result="<<reverseint(i)<<endl;
    cout<<"三.函数"<<endl;
    cout<<"1.诗"<<endl;
    cout<<dopoem();
    cout<<endl<<"2.闰年"<<endl;
    cout<<"请输入年份:";
    cin>>year;
    cout<<Isleap(year)<<endl;
    cout<<"四.数组"<<endl;
    for(int i = 0;i<10;i++){
        cin>>farr[i];
    }
    cout<<"数组：";
    for(int i = 0;i<10;i++){
       cout<<farr[i]<<" ";
    }
    cout<<"输入n：";
    cin>>n;
    cout<<"数组前"<<n<<"位最小值为"<<min(farr,n)[0]<<"下标为"<<min(farr,n)[1];
    system("pause");
    return 0;
}