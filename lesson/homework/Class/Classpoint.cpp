#include<iostream>
using namespace std;
class Point
{
    private:
        int _x,_y;
    public:
        Point()
        {
            _x=0,_y=0;
        }
        Point(int x,int y)
        {
            _x=x,_y=y;
        }
        void display()
        {
            cout<<"("<<_x<<", "<<_y<<")"<<endl;
        }
        Point  operator ++()
        {

            return Point(++_x,++_y);//返回临时对象
        }
        Point operator ++(int)
        {
            return Point(_x++,_y++);
        }
        Point operator --()
        {
            return Point(--_x,--_y);
        }
        Point operator --(int)
        {
            return Point(_x--,_y--);
        }
};
int main()
{
    int x,y;
    cin>>x>>y;
    Point p(x,y),p1;
    
    p.display();
    p1=p++;
    p1.display();
    p1=++p;
    p1.display();
    p1=p--;
    p1.display();
    // p1=--p;
    p1.display();
    return 0;
}
