#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char t[MAXN], s[MAXN];
    int m;

    scanf("%d\n", &m);
    ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
void strmcpy( char *t, int m, char *s )
{
    if(m > MAXN) {
        *s = 0;
    } else {
        int j = 0;
        while(m <= MAXN) {
            s[j++] = t[m++ - 1];
        }
    }
}
void ReadString( char s[] )
{
    s[0] = 'h';
    s[1] = 'a';
    s[2] = 'p';
    s[3] = 'p';
    s[4] = 'y';
    s[5] = ' ';
    s[6] = 'n';
    s[7] = 'e';
    s[8] = 'w';
    s[9] = ' ';
    s[10] = 'y';
    s[11] = 'e';
    s[12] = 'a';
    s[13] = 'r';
    s[14] = 0;
}