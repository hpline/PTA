#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}

/* 你的代码将被嵌在这里 */
void dectobin( int n )
{
    if(n <= 1) {
        printf("%d", n);
        return ;
    }
    dectobin(n >> 1);
    printf("%d", n % 2);
}