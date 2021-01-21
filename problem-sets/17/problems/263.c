#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxDigits     32
#define BASE          10

char *Double(char src[], char dest[]);
const char *Check(char src[], char dest[]);

int main()
{
    char src[MaxDigits];
    char dest[MaxDigits];
    char *res;
    scanf("%s", src);
    res = Double(src, dest);
    printf("%s\n", Check(src, res));
    printf("%s\n", res);
    return 0;
}

const char *Check(char src[], char dest[])
{
    char base1[BASE];
    char base2[BASE];
    memset(base1, 0, BASE);
    memset(base2, 0, BASE);
    while(*src) base1[*(src++)-'0']++;
    while(*dest) base2[*(dest++)-'0']++;
    for (int i = 0; i < BASE; i++) 
        if(base1[i] != base2[i]) return "No";
    return "Yes";
}

char *Double(char src[], char d[])
{
    size_t len = strlen(src);
    memset(d, 0, MaxDigits);
    d[0] = '0';
    for(size_t i = 0; i < len; i++) {
        int digit = (src[i] - '0') << 1;
        d[i] += digit / BASE, d[i+1] += digit % BASE + '0';
    }
    if(d[0]=='0') return d+1;
    else return d;
}
