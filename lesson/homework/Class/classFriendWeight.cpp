#include <iostream>
using namespace std;

class Car; // class Boat 中引用了Car类的对象，所以要预先声明

class Boat
{
public:
    Boat(float w) : weight(w) {}
    Boat(Boat &b) : weight(b.weight) {}
    ~Boat() {}
    friend void getTotalWeight(Boat &b, Car &c); // 友元函数参数为引用

private:
    float weight;
};

class Car
{
public:
    Car(float w) : weight(w) {}
    Car(Car &c) : weight(c.weight) {}
    ~Car() {}
    friend void getTotalWeight(Boat &b, Car &c);

private:
    float weight;
};

void getTotalWeight(Boat &b, Car &c)
{
    float sum = b.weight + c.weight;
    cout << sum << endl;
}

int main()
{
    float k,l;
    cin>>k>>l;
    Boat b(k);
    Car c(l);
    getTotalWeight(b,c);
    system("pause");
    return 0;
}