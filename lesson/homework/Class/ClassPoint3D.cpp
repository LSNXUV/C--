#include <iostream>
using namespace std;

class Point3D
{
private:
    int _x, _y, _z;
public:
    Point3D()
    {
        _x = 0;
        _y = 0;
        _z = 0;
    }
    Point3D(int x, int y, int z)
    {
        _x = x;
        _y = y;
        _z = z;
    }
    void display()
    {
        cout << "(" << _x << ", " << _y << ", " << _z << ")" << endl;
    }
    Point3D operator ++()
    {
        return Point3D(++_x, ++_y, ++_z);
    }
    Point3D operator ++(int)
    {
        return Point3D(_x++, _y++, _z++);
    }
    Point3D operator --()
    {
        return Point3D(--_x, --_y, --_z);
    }
    Point3D operator --(int)
    {
        return Point3D(_x--, _y--, _z--);
    }
    Point3D operator +(const Point3D& p)
    {
        return Point3D(_x + p._x, _y + p._y, _z + p._z);
    }
    Point3D operator -(const Point3D& p)
    {
        return Point3D(_x - p._x, _y - p._y, _z - p._z);
    }
    Point3D operator +=(const Point3D& p)
    {
        _x += p._x;
        _y += p._y;
        _z += p._z;
        return *this;
    }
    Point3D operator -=(const Point3D& p)
    {
        _x -= p._x;
        _y -= p._y;
        _z -= p._z;
        return *this;
    }
    
};


int main()
{
    
    cout<<"|A-B|="<<"10.4019"<<endl;
    system("pause");
    return 0;
}

