#include <stdio.h>

double fact( int n );
double factsum( int n );

int main()
{
    int n;

    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));

    return 0;
}

/* 你的代码将被嵌在这里 */
double fact( int n )
{
    if(n < 0) {
        return 0;
    } else if(n <= 1) {
        return 1;
    }
    return fact(n-1) * n;
}
double factsum( int n )
{
    double sum;
    if(n <= 0) {
        return 0;
    } else if(n <= 1) {
        return 1;
    }
    for(int i = 1; i <= n; i++) {
        sum += fact(i);
    }
    return sum;
}