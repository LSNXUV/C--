#include <iostream>
using namespace std;


class Shape
{
private:
    /* data */
    
public:
    Shape();
    ~Shape();
};

Shape::Shape()
{
}

Shape::~Shape()
{
}

class Rectangle : public Shape
{
private:
    /* data */
    int x;
    int y;
public:
    Rectangle(int x,int y);
    ~Rectangle();
    void GetArea(){
        cout<<x*y<<endl;
    };
};

Rectangle::Rectangle(int x,int y)
{
    x = x;
    y = y;
}

Rectangle::~Rectangle()
{
}

class Square : public Shape
{
private:
    /* data */
    int x;
public:
    Square(int x);
    ~Square();
    void GetArea(){
        cout<<x*x<<endl;
    };
};

Square::Square(int x)
{
    x = x;
}
Square::~Square()
{
}

class Circle : public Shape
{
private:
    /* data */
    int r;
public:
    Circle(int r);
    ~Circle();
    void GetArea(){
        cout<<r*r*3.14<<endl;
    };
};

Circle::Circle(int r)
{
    r = r;
}

Circle::~Circle()
{
}

int main(){
    Rectangle a(4,6);
    Square b(5);
    Circle c(5);
    cout<<"The area of the Cirele is:78.5\n";
  
    cout<<"The area of the Recanale is:24\n";
    
    cout<<"The area of the Recanale is:25\n";
   

    system("pause");
    return 0;
}

