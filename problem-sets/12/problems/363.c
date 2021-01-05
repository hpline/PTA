#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */
char *match( char *s, char ch1, char ch2 )
{
    char ch = *s;
    char *ret = "\n";
    int flag = 0;
    while(ch) {
        if(flag == 0) {
            if(ch == ch1) {
                flag = 1;
                ret = s;
                printf("%c", ch);
            }
        } else if(flag == 1) {
            if(ch == ch2) {
                flag = 2;
            }
            printf("%c", ch);
        }
        ch = *(++s);
    }
    if(flag) {
        printf("\n");
    }
    return ret;
}