#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
float applecost(){
    double sum = 0;
    int i = 2;
    int j = 0;
    for(i;i<=100;i*=2)
    {
        sum = sum + i*0.2;
        j++;
    }
    return sum/j;
}
bool isprime(int n){
    if(n==1&&n==2&&n==3)
    {
        return true;
    }
    for(int i = 2;i<sqrt(n);i++)
    {
        if((n % i) == 0){
            cout<<n<<"不是素数"<<endl;
            return false;
        }
    }
    cout<<n<<"是素数"<<endl;
    return true;
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
typedef struct 
{
    int citynum;
    char name[17];
    double longitude;
    double lagitude;
} city;

city arr[20];
void incities(int cities){
    for(int i = 0;i < cities;i++){
        cout<<"请输入第"<<i+1<<"个城市编号:"<<endl;
        cin>>arr[i].citynum;
        cout<<"请输入第"<<i+1<<"个城市名称:"<<endl;
        cin>>arr[i].name;
        cout<<"请输入第"<<i+1<<"个城市经度"<<endl;
        cin>>arr[i].longitude;
        cout<<"请输入第"<<i+1<<"个城市纬度"<<endl;
        cin>>arr[i].lagitude;
    }
};
void outcities(int cities){
    cout<<"-------------------------------------"<<endl;
    cout<<"|城市名称|城市编号|城市经度|城市维度|"<<endl;
    for(int i = 0;i < cities;i++){
        cout<<"|    "<<arr[i].name<<"|\t "<<arr[i].citynum<<"|  "<<arr[i].longitude<<
        "|   "<<arr[i].lagitude<<"|"<<endl;
    }
}
int main(){
    int n;
    int rens;
    int cities;
    double salary[20];
    cout<<"一.循环结构:"<<endl;
    cout<<applecost()<<endl;
    cout<<"二.数组与函数"<<endl;
    cout<<"2.1:"<<endl;
    cout<<"请输入正整数判断是否为素数:";
    cin>>n;
    isprime(n);
    cout<<"2.2:"<<endl;
    cout<<"请输入统计人数:";
    cin>>rens;
    avrsalary(rens);
    cout<<"三.结构体、数组与函数"<<endl;
    cout<<"3.1:"<<endl;
    cout<<"请输入要写入的城市数量:"<<endl;
    cin>>cities;
    incities(cities);
    outcities(cities);
    system("pause");
    return 0;
}