#include <iostream>
using namespace std;



int main(){
    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    if((hour == 12 && minute == 0) || (hour >= 0 && hour <= 11)){
        printf("Only %02d:%02d.  Too early to Dang.", hour, minute);
    }else{
        int count = hour - 12;
        if(minute > 0){
            count++;
        }
        for(int i = 0; i < count; i++){
            printf("Dang");
        }
    }
    system("pause");
    return 0;
}