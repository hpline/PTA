#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int narcissistic( int number )
{
    int temp = number;
    int digit = 0;
    int multi = 1;
    int bits = 0;
    if(number < 100) return 0;
    while(number) {
        bits++;
        number /= 10;
    }
    number = temp;
    while(number) {
        multi = 1;
        digit = number % 10;
        for(int i = bits; i > 0; i--) {
            multi *= digit;
        }
        temp -= multi;
        number /= 10;
    }
    if(temp == 0) return 1;
    return 0;
}
void PrintN( int m, int n )
{
    for(int i = m + 1; i < n; i++) {
        if(narcissistic(i)) {
            printf("%d\n", i);
        }
    }
}