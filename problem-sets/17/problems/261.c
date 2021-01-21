#include <stdio.h>
#include <math.h>

int Pair(int n);

int main()
{
    int  x;
    scanf("%d", &x);
    printf("%d\n", Pair(x));
    return 0;
}

int IsPrime(int x)
{
    int max = sqrt(x);
    for(int i = 2; i <= max; i++) if(x % i == 0) return 0;
    return 1;
}

int NextPrime(int prime, int n)
{
    int i = prime+1;
    while(i <= n) {
        if(IsPrime(i)) return i;
        i++;
    }
    return -1;
}

int Pair(int n)
{
    int pn0, pn1, count;
    if(n < 2) return 0;
    count = 0;
    pn0 = 2;
    while(1) {
        pn1 = NextPrime(pn0, n);
        if(pn1 == -1) break;
        if(pn1 - pn0 == 2) count++;
        pn0 = pn1;
    }
    return count;
}
