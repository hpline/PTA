#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);

    return 0;
}

/* 你的代码将被嵌在这里 */
void delchar( char *str, char c )
{
    char *mov = 0;
    for(int j = 0; j < MAXN; j++) {
        if(str[j] == c) {
            if(mov == 0) {
                mov = str + j;
            }
            continue;
        } else {
            if(mov) {
                *(mov++) = str[j];
            }
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