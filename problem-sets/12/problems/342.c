#include <stdio.h>
#include <string.h>

#define MAXN 20
typedef enum {false, true} bool;

bool palindrome( char *s );

int main()
{
    char s[MAXN];

    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
bool palindrome( char *s )
{
    int i = 0;
    do {
        if(s[i] == 0) {
            break;
        }
        i++;
    } while(i < MAXN);
    for(int j = 0, k = i - 1; j < k; j++, k--){
        if(s[j] != s[k]) {
            return false;
        }
    }
    return true;
}