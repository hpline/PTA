#include <stdio.h>

int reverse( int number );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

/* 你的代码将被嵌在这里 */
int reverse( int number )
{
    int ret = 0;
    int digit = 0;
    while(number) {
        ret *= 10;
        digit = number % 10;
        ret += digit;
        number /= 10;
    }
    return ret;
}