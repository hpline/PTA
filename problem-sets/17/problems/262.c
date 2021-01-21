#include <stdio.h>
#include <stdlib.h>

void shift(int a[], int n, int m);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *a = malloc(sizeof(*a)*n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    shift(a, n, m);
    for(int i = 0; i < n-1; i++) printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    return 0;
}

void reverse(int a[], int begin, int end)
{
    while (begin < --end) {
        int temp = a[end];
        a[end] = a[begin];
        a[begin++] = temp;
    }
} 

void shift(int a[], int n, int m)
{
    m = m % n;
    reverse(a, 0, n-m);
    reverse(a, n-m, n);
    reverse(a, 0, n);
}