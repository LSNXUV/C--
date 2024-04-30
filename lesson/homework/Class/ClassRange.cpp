#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle(float a, float b)
    {
        width = a;
        length = b;
    }
    float getArea()
    {
        return width * length;
    }
    float width;
    float length;
     
};

class Cube : public Rectangle
{
public:
    float height;
    Cube(float a, float b,float c) : Rectangle(a, b)
    {
    
        height = c;
       
    }
    float getVolume()
    {
        return Rectangle::getArea() * height;
    }
    float getSurfaceArea()
    {
        return 2 * Rectangle::getArea() + 2 * width * height + 2 * length * height;
    }
    void out(){
        cout<<"length="<<width<<"  "<<"width="<<length<<"  "<<"height="<<height<<endl;
    }
};



int main(){
    float a,b,c;
    cout<<"输入长方体的长、宽、高："<<endl;
    cin>>a>>b>>c;
    Cube cube(a,b,c);
    cube.out();
    cout<<"表面积="<<cube.getSurfaceArea()<<"  ";
    cout<<"体积="<<cube.getVolume()<<endl;


    system("pause");
    return 0;
}