#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct Record
{
    int time;
    bool isBorrowed = false;
} records[10000];

int main()
{
    int n;
    cin >> n;
    int day = 0;
    int count = 0;
    int sum = 0;
    while(day < n)
    {
        int id, h, m;
        char type;
        scanf("%d %c %d:%d", &id, &type, &h, &m);
        if (id == 0){
            if(count == 0){
                cout << 0 <<" "<< 0 << endl;
            }else{
                cout << count << " " << round((double)sum / count) << endl;
                memset(records, 0, sizeof(Record) * 10000);
                count = 0;
                sum = 0;
            }
            day++;
        }else{
            if (type == 'S'){
                records[id].isBorrowed = true;
                records[id].time = h * 60 + m;
            }
            else if (records[id].isBorrowed == true){
                records[id].isBorrowed = false;
                records[id].time = h * 60 + m - records[id].time;
                sum += records[id].time;
                count++;
            }
        }
    }

    system("pause");
    return 0;
}