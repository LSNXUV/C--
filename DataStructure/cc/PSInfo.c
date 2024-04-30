#include <stdio.h>



int main(){
    int n,age,a,b,c,d,e,f;
    char name[20];
    scanf("%d %s %d",&n,name,&age);
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    printf("%d %s %d\n",n,name,age);
    printf("%d",
        ((a > 59) ? 4 : 0)+
        ((b > 59) ? 3 : 0)+
        ((c > 59) ? 4 : 0)+
        ((d > 59) ? 3 : 0)+
        ((e > 59) ? 3 : 0)+
        ((f > 59) ? 3 : 0)
    );

return 0;
}