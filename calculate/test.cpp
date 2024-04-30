#include <iostream>
#include <cstring>
using namespace std;

void fun(char *str)
{
    str[1] = 'd';
}

int main(){
    char str[5];
    fun(str);

    cout<<str[1];

    system("pause");
    return 0;
}