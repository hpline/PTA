#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int fib( int n )
{
    int f1 = 1;
    int f2 = 1;
    int f = 0;
    if(n <= 0) {
        return 0;
    } else if(n <= 2) {
        return 1;
    }
    for(int i = 0; i < n - 2; i++) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f2;
}
void PrintFN( int m, int n )
{
    int flag = 0;
    for(int i = 1; i <= n+1; i++) {
        int f = fib(i);
        if(f >= m && f <= n) {
            if(flag) {
                printf(" ");
            }
            printf("%d", f);
            flag = 1;
        } else if(f > n+1) {
            break;
        }
    }
    if(flag == 0)
        printf("No Fibonacci number\n");
    else 
        printf("\n");
}