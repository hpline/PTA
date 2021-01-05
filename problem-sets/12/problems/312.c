#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
int prime( int p )
{
    if(p <= 1) {
        return 0;
    }
    for(int i = 2; i <= p/2; i++) {
        if(p % i == 0) {
            return 0;
        }
    }
    return 1;
}
void Goldbach( int n )
{
    int r;
    if(n < 4) {
        return ;
    }
    for(int i = 2; i <= n/2; i++) {
        if(prime(i)) {
            r = n - i;
            if(prime(r)) {
                printf("%d=%d+%d", n, i, r);
                return ;
            }
        }
    }
    return ;
}