#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

/* 你的代码将被嵌在这里 */
double funcos( double e, double x )
{
    double ret = 1;
    double factor = 1;
    double temp = factor;
    int flip = 1;
    int power = 0;
    double factorial = 1;
    while(factor > e) {
        for(int i = power + 1; i <= power + 2; i++) {
            factorial *= i;
        }
        power += 2;
        factor = pow(x, power) / factorial;
        if(flip) {
            temp = -factor;
            flip = 0;
        } else {
            temp = factor;
            flip = 1;
        }
        ret += temp;
    }
    return ret;
}