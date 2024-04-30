#include <iostream>
#include <iomanip>
#include <set>
#include <string>
using namespace std;

int main(){
    int start, n;
    int age = 0;
    set<int> s;
    cin>>start>>n;
    string strYear;
    while(s.size() != n){
        s.clear();
        strYear = to_string(start);
        for(char c:strYear){
            s.insert(c);
        }
        if(strYear.length() < 4){
            s.insert('0');
        }
        age++;
        start++;
    }
    cout<<age-1<<" "<<setfill('0')<<setw(4)<<start-1<<endl;

    system("pause");
    return 0;
}