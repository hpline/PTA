#include <stdio.h>
#define MAXN 10

int ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

    ArrayShift(a, n, m);

    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int ArrayShift( int a[], int n, int m )
{
    int m1;
    int m2;
    if(m > n) {
        m = m % n;
    }
    m1 = m;
    m2 = n - m;
    while(m1) {
        m1 = m2 - m;
        if(m1 < 0) {
            m1 = 0;
        }
        for(int i = 0; i < m; i++) {
            int tmp;
            tmp = a[m1 + i];
            a[m1 + i] = a[m2 + i];
            a[m2 + i] = tmp;
        }
        m2 = m1;
    }
    return 0;
}