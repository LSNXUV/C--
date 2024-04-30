#include <iostream>
using namespace std;

class Circle
{
    private:
        /* data */
    public:
        int Radius;
        int IRadius;
    float GetArea();
    void setR(int r,int r1);
    int GetI();
};

void Circle::setR(int r,int r1 = 0){
    Radius = r;
    IRadius = r1;
}
float Circle::GetArea(){
    return Radius*Radius*3.14-IRadius*IRadius*3.14;
}
int Circle::GetI(){
    return IRadius;
};



int main(){
    Circle c;
    int a,b;
    cin>>a;
    while(cin>>b){
    if(cin.get()=='\n'){
        break;
    }
    break;
    };
    c.setR(a,b);
    cout<<"the circle is created!"<<endl;
    if (c.GetI()==0)
    {
        cout<<"the area is:"<<c.GetArea();
        return 0;
    }
    cout<<"the ring's area is:"<<c.GetArea();
    system("pause");
    return 0;
    
}
