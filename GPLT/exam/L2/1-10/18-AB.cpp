#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int nonNegativeNum(double c[], int start) {
    int cnt = 0;
    for (int i = start; i >= 0; i--)
        if (abs(c[i]) + 0.05 >= 0.1) 
            cnt++;
    return cnt;
}

void printPoly(double c[], int start) {
    printf("%d", nonNegativeNum(c, start));
    if (nonNegativeNum(c, start) == 0) printf(" 0 0.0");
    for (int i = start; i >= 0; i--)
        if (abs(c[i]) + 0.05 >= 0.1)
            printf(" %d %.1f", i, c[i]);
}

double c1[3000], c2[3000], c3[3000];    // c1, c2, c3分别存储被除数、除数、商
int main() {
    int m = 0, n = 0, t = 0;    // m, n分别存储被除数、除数的项数, t存储指数,
    int max1 = -1, max2= -1;    //max1, max2分别存储被除数、除数的最大指数
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        max1 = max(max1,t);
        scanf("%lf", &c1[t]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        max2 = max(max2,t);
        scanf("%lf", &c2[t]);
    }
    int t1 = max1, t2 = max2;
    while (t1 >= t2) {
        double c = c1[t1] / c2[t2];   // c为当前商的一个项的系数
        c3[t1 - t2] = c;    // t1 - t2为当前商的一个项的指数
        for (int i = t1, j = t2; j >= 0; j--, i--) 
            c1[i] -= c2[j] * c;     // 除完后的被除数的系数，例如4x^3除以2x^2，得到的商为4/2=2^x^(3-2)=2x,然后被除数系数=4-2*2=0。
        while (abs(c1[t1]) < 0.1) 
            t1--;
    }
    printPoly(c3, max1 - max2);
    printf("\n");
    printPoly(c1, t1);
    return 0;
}