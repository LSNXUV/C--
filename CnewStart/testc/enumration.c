#include <stdio.h>

int main(){

    enum DAY {
        mon = 1,
        tus,
        wen,
        thu,
        fri,
        sat,
        sun
    } day;

    day = sun;

    printf("weekend:%d",day);
    for(int a = mon;a < sun;a++){
        printf("weekend %d:%d\n",a,a);
    }







}