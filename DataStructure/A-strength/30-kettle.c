#include <stdio.h>


int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

int main(){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x+y < z)
    {
        return printf("fail");
    }
    if(z/gcd(x,y)){
        return printf("fail");
    }
    
    return 0;
}