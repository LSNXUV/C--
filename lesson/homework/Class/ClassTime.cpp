#include <iostream>
using namespace std;

class Time
{
private:
    /* data */
public:
    int hours;
    int minutes;
    int seconds;
    Time(int h,int m,int s);
    
};
Time::Time(int h,int m,int s){
    hours = h;
    minutes = m;
    seconds = s;
    if(seconds>=60){
        minutes+=s/60;
        seconds = s%60;
    };
    if(minutes>=60){
        hours+=minutes/60;
        minutes = minutes%60;
    };
    if(hours>=24){
        hours = hours%24;
    }
    
}



int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c;
    cin>>d>>e>>f;
    Time time(a+d,b+e,c+f);
    cout<<"the result is:"<<time.hours<<":"<<time.minutes<<":"<<time.seconds;
    

    system("pause");
    return 0;
}