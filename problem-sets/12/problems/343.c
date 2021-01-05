#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

/* Your function will be put here */
void StringCount( char *s )
{
    int digit = 0;
    int ch = 0;
    int CH = 0;
    int blank = 0;
    int other = 0;
    while(*s != 0) {
        char c = *(s++);
        if(c >= 'A' && c <= 'Z') {
            CH++;
        } else if(c >= 'a' &&  c <= 'z') {
            ch++;
        } else if(c >= '0' &&  c <= '9') {
            digit++;
        } else if(c == ' ') {
            blank++;
        } else {
            other++;
        }
    }
    printf("%d %d %d %d %d\n", CH, ch, blank, digit, other);
}
void ReadString( char *s )
{
    s[0] = 'a';
    s[1] = 'Z';
    s[2] = '&';
    s[3] = '*';
    s[4] = '?';
    s[5] = '\n';
    s[6] = '0';
    s[7] = '9';
    s[8] = '3';
    s[9] = ' ';
    s[10] = 'A';
    s[11] = 'z';
    s[12] = 0;
}