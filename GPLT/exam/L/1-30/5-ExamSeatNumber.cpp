#include <iostream>
using namespace std;

struct Seat
{
    char id[17];
    int testSeat;
    int examSeat;
};



int main(){

    int n;
    cin >> n;
    Seat *seats = new Seat[n];
    for(int i = 0; i < n; i++){
        cin >> seats[i].id >> seats[i].testSeat >> seats[i].examSeat;
    }
    //�����ѯѧ������
    int m;
    cin >> m;
    int *testSeats = new int[m];
    //�����ѯѧ���Ŀ�����λ��
    for(int i = 0; i < m; i++){
        cin >> testSeats[i];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(seats[j].testSeat == testSeats[i]){
                cout << seats[j].id << " " << seats[j].examSeat << endl;
                break;
            }
        }
    }
    // delete[] seats;

    system("pause");
    return 0;
}