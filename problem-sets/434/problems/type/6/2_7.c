#include <stdio.h>
#define TOL 1E-2

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

/* 你的代码将被嵌在这里 */
double dist( double h, double p )
{
    if(h == 0) return 0;
    if(h*p < TOL) return h;
    return h + h*p + dist(h*p, p);
}