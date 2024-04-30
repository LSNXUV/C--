#include <iostream>
using namespace std;



int main(){
    int day;
    cin >> day;
    cout << (day > 5 ? (day + 2) % 7 : day + 2); 

    system("pause");
    return 0;
}