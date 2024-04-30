#include <iostream>
#include <cmath>
#include<iomanip>
#include <string>
#include <cstring>
using namespace std;

float pi = 3.1415;
int a,b,c,celsius,year;
float r;
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
    cout<<"(һ)";
    cout<<"Because of the new coronavirus, we have online classes at home"<<endl<<"һ��һ���磬һ��һ����----����Ԫ"<<endl;
    cout<<"(��.1)"<<endl<<"��������뾶:";
    cin>>r;
    cout.precision(5);
    cout<<"���Ϊ:"<<area(r);
    cout<<"���Ϊ:"<<volume(r)<<endl;
    cout<<"(��.2)"<<endl<<"��������������(�Կո�ָ�):";
    cin>>a>>b>>c;
    cout<<"���Ϊ:"<<max(max(a,b),c)<<endl;
    cout<<"(��).1"<<endl;
    cout<<"���������϶�:";
    cin>>celsius;
    cout<<"���Ӧ���϶�Ϊ:";
    cout<<fixed<<setprecision(1)<<Fahrenheit(celsius);;
    cout<<endl<<"(��).2"<<endl;
    cout<<"���������:";
    cin>>year;
    cout<<to_string(year)<<Isleap(year);
    
    system("pause");
return 0;
}