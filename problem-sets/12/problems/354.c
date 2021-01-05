#include <stdio.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

/* 你的代码将被嵌在这里 */
double fn( double x, int n )
{
    double ret = 1;
    if(n == 0) {
        return 0;
    }
    for(int i = 0; i < n; i++) {
        ret *= x;
    }
    if(n % 2 == 0) {
        ret = -ret; 
    }
    return ret + fn(x, n-1);
}