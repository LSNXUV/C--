#include<iostream>
using namespace std;
class Circle
{
 private:
 float r;
    public:
     Circle():PI(3.1415926)
     {
     r=0;
 }
 Circle(float r):r(r),PI(3.1415926)
 {
 }
 void printInfor()
 {
 cout<<"r:"<<r<<endl;
 }
 void Girth(float r)
 {
 float c;
 c=2*PI*(r+3);

 cout<<"the fencing cost is:"<<c*35<<endl;  
 }
   
 void Area(float r)//小圆面积 
 {
 float s1;
 s1=PI*r*r;

 
 float s2;
 s2=PI*(r+3)*(r+3);
 
 cout<<"the concrete cost is:"<<(s2-s1)*20<<endl; 
 }
 const double PI;  
};




int main()
{
 Circle c1;
 float r;

 cin>>r;
 c1.Girth(r);


 cout<<endl;
 c1.Area(r);
 
 cout<<endl;  
     
 return 0;
}