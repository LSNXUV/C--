#include <stdio.h>


int main(){
    int days = 0;
    int year,month,day,i;
    scanf("%d %d %d",&year,&month,&day);
    days+=day;
    int year1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i = 0;i<month-1;i++){
			days+=year1[i];
	}
    if(((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))&&month>=3){
        days++;
    }
    printf("%d",days);
    // scanf("%d",&year);
    return 0;
}
