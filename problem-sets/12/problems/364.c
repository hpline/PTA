#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char *search(char *s, char *t)
{
    int len = 0;
    for(len = 0; len < MAXS; len++) {
        if(t[len] == 0) {
            break;
        }
    }
    for(int i = 0; i < MAXS; i++) {
        int j;
        if(s[i] == 0) {
            break;
        }
        for(j = 0; j < len; j++) {
            if(s[i+j] != t[j]) {
                break;
            }
        }
        if(j == len) {
            return &s[i];
        }
    }
    return NULL;
}
void ReadString( char s[] )
{
    static int i = 0;
    if(i == 0) {
        s[0] = 'p';
        s[1] = 'o';
        s[2] = 'g';
        s[3] = 'r';
        s[4] = 'a';
        s[5] = 'm';
        s[6] = 0;
        i = 1;
    } else {
        s[0] = 'r';
        s[1] = 'a';
        s[2] = 'm';
        s[3] = 0;
    }
}