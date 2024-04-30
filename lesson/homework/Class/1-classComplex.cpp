#include <iostream>
using namespace std;


class Complex
{
    private:
        double real,image;
    public:
        Complex(double x=0.0,double y=0.0)
        {
            real=x,image=y;
        }
        void display()
        {
            cout<<real<<"+i"<<image<<endl;
        }
        Complex operator +(Complex B)
        {
            return Complex(real+B.real,image+B.image);
        }
        //与实数相加，重载为类的友元函数
        friend Complex operator +(double x,Complex A)
        {
            return Complex(A.real+x,A.image);
        }
        Complex operator -(Complex B)
        {
            return Complex(real-B.real,image-B.image);
        }
        //与实数相减
        Complex operator -(double x)
        {
            return Complex(real-x,image);
        }

};

int main(){
Complex a(2,5),b(7,8),c(0,0);
    c=a+b;
    c.display();
    c=4.1+a;
    c.display();
    c=b-5.6;
    c.display();

    system("pause");
    return 0;
}