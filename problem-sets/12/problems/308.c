#include <stdio.h>
#define MAXS 15

void StringCount( char s[] );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

/* Your function will be put here */
void StringCount( char s[] )
{
    int letter, blank, digit, other;
    letter = blank = digit = other = 0;
    while(*s) {
        char ch = *(s++);
        if(ch >= 'A' && ch <= 'Z') {
            letter++;
        } else if(ch >= 'a' && ch <= 'z') {
            letter++;
        } else if(ch >= '0' && ch <= '9') {
            digit++;
        } else if(ch == ' ' || ch == '\n') {
            blank++;
        } else {
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n", letter, blank, digit, other);
}
void ReadString( char s[] )
{
    s[0] = 'a';
    s[1] = 'Z';
    s[2] = ' ';
    s[3] = '&';
    s[4] = '\n';
    s[5] = '0';
    s[6] = '9';
    s[7] = ' ';
    s[8] = 'A';
    s[9] = 'z';
    s[10] = 0;
}