#include <stdio.h>
#include <string.h>

    union Data {
        int a;
        char str[20];
        double c;
    };

int main(){
    union Data data;
    data.a = 100;
   printf( "data.i : %d\n", data.a);
   
   data.c = 220.5;
   printf( "data.f : %f\n", data.c);
   
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);

    return 0;
}