#include <stdio.h>

/* void is_leap_year(int year){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        printf("YES");
    }
    printf("NO");
} */


int main(){
    int year;
    scanf("%d",&year);
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        printf("YES");
    }else
    printf("NO");
    scanf("%d",&year);
return 0;
}