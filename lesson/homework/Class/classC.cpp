#include <iostream>
using namespace std;

class Base
{
public:
    void fn1()
    {
        cout<<"the fn1 founction of the baseclass"<<endl;
    }
    void fn2()
    {
        cout<<"the fn2 founction of the baseclass"<<endl;
    }
};
class Derived:public Base
{
public:
    void fn1()
    {
        cout<<"the fn1 founction of the DerivedClass"<<endl;
    }
    void fn2()
    {
        cout<<"the fn2 founction of the DerivedClass"<<endl;
    }
};


int main(){
    Derived d;
    d.fn1();
    d.fn2();
     Base *p1=&d;
    p1->fn1();
    p1->fn2();
    Derived *p2=&d;
    p2->fn1();
    p2->fn2();

    system("pause");
    return 0;
}