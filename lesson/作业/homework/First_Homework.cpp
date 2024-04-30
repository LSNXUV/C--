#include <iostream>
#include <cmath>
#include<iomanip>
#include <string>
#include <cstring>

using namespace std;

float pi = 3.1415;
int a,b,c,year;
float r,celsius;



float area(float radius){
    return pow(radius,2)*pi*4;
};



float volume(float radius){
    return pow(radius,3)*pi*4/3;
};




int max(int a,int b){
    return a > b ? a : b;
}



float Fahrenheit(float celsius){
    return celsius*9/5+32;
}
char* Isleap(int year){
    static char isleap[70];
    static char isnotleap[70];
    strcpy(isleap," is leapyear");
    strcpy(isnotleap," is not leapyear");
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ){
	    return isleap;
    } return isnotleap;
}

int main(){
    cout<<"(一)";
    cout<<"Because of the new coronavirus, we have online classes at home"<<endl<<"一花一世界，一句一迭代----梁新元"<<endl;



    cout<<"(二.1)"<<endl<<"请输入球半径:";
    cin>>r;
    cout.precision(5);
    cout<<"面积为:"<<area(r);
    cout<<"体积为:"<<volume(r)<<endl;



    cout<<"(二.2)"<<endl<<"请输入三个数字(以空格分隔):";
    cin>>a>>b>>c;
    cout<<"最大为:"<<max(max(a,b),c)<<endl;
    cout<<"(三).1"<<endl;
    cout<<"请输入摄氏度:";
    cin>>celsius;
    cout<<"其对应华氏度为:";
    cout<<fixed<<setprecision(1)<<Fahrenheit(celsius)<<"℃";
    cout<<endl<<"(三).2"<<endl;
    cout<<"请输入年份:";
    cin>>year;
    cout<<to_string(year)<<Isleap(year);
    
    system("pause");
return 0;
}