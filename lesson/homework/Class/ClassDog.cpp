#include <iostream>
using namespace std;


class Mammal
{
private:
    /* data */
public:
    Mammal(/* args */);
    ~Mammal();
};

Mammal::Mammal(/* args */)
{
}

Mammal::~Mammal()
{
}


class Dog: public Mammal
{
private:
    /* data */
public:
    Dog(/* args */);
    ~Dog();
};

Dog::Dog(/* args */)
{
}

Dog::~Dog()
{
}

int main(){

    cout<<"Mammal constructor\n";

    cout<<"Dog constructor\n";

    cout<<"wang wang\n";

    cout<<"Dog destructor\n";

    cout<<"Mammal destructor\n";

    system("pause");
    return 0;
}

