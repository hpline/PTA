#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* 实现细节在此不表 */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);

    return 0; 
}

/* 你的代码将被嵌在这里 */
void Shift( char s[] )
{
    char c1 = s[0];
    char c2 = s[1];
    char c3 = s[2];
    char *p = s + 3;
    while(*p) {
        *s = *p;
        p++;
        s++;
    }
    s[0] = c1;
    s[1] = c2;
    s[2] = c3;
}
void GetString( char s[] )
{
    s[0] = 'a';
    s[1] = 'b';
    s[2] = 'c';
    s[3] = 'd';
    s[4] = 'e';
    s[5] = 'f';
    s[6] = 0;
}