#include <stdio.h>

void pyramid( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}

/* 你的代码将被嵌在这里 */
void pyramid( int n )
{
    for(int i = 1; i <= n; i++) {
        for(int j = n - i; j > 0; j--) 
            printf(" ");
        for(int k = i; k > 0; k--)
            printf("%d ", i);
        printf("\n");
    }
}