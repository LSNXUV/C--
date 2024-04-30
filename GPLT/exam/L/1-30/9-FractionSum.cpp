#include <iostream>
#include <string>
using namespace std;

// ���Լ��
long gcd(long x,long y){
    return y?gcd(y,x%y):x;
}

// ��С������
long lcm(long x,long y){
    return x*y/gcd(x,y);
}

int main(){
    int n;
    cin>>n;

    long numerator = 0;
    long denominator = 1;

    for(int i = 0;i<n;i++){
        long num,den;
        scanf("%ld/%ld",&num,&den);
        numerator = numerator*den + num*denominator;
        denominator = den*denominator;
        long g = gcd(numerator,denominator);
        numerator /= g;
        denominator /= g;
    }

    if(numerator%denominator==0){
        cout<<numerator/denominator<<endl;
    }else if(numerator < denominator){
        cout<<numerator<<"/"<<denominator<<endl;
    }else{
        cout<<numerator/denominator<<" "<<numerator%denominator<<"/"<<denominator<<endl;
    }

    system("pause");
    return 0;
}