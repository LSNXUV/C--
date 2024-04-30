#include <stdio.h>
#include <stdarg.h>

double avrange(int num,...){
    double sum = 0.0;
    int i;
    va_list valist;

    va_start(valist,num);

    for(i = 0;i < num;i++){
        sum += va_arg(valist,int);

    }
    va_end(valist);
    return sum/num;
};

int main(){
    printf("%f\n",avrange(3,6,8,45));
    getchar();
    
return 0;
}