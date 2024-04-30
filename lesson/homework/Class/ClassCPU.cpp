#include <iostream>
using namespace std;

enum C {P1=1,P2,P3,P4,P5,P6,P7}C;
class CPU
{
    private:
        /* data */
    public:
        enum {P1=1,P2,P3,P4,P5,P6,P7}C;
        int frequeney;
        float volage;
    void setfv(enum C c,int f,float v);

};

int main(){
    cout<<"one CPU is created!"<<endl;

cout<<"CPU is running!"<<endl;
cout<<"CPU stop!"<<endl;
cout<<"one CPU is distoried!";


    

    system("pause");
    return 0;
}
