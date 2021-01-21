#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hourglass(int n, char ch);

int main()
{
    int  x;
    char ch;
    scanf("%d %c", &x, &ch);
    printf("%d\n", hourglass(x, ch));
    return 0;
}

int hourglass(int n, char ch)
{
    if(n <= 0) return 0;
    int length = sqrt((n+1)>>1)*2-1;
    length = length%2==0 ? length-1 : length;
    for (int i = 0; i < length; i++) {
        int mark = abs(length-1-i*2)+1;
        int blank = (length - mark) >> 1;
        for (int j = 0; j < blank; j++) printf("%c", ' ');
        for (int j = 0; j < mark;  j++) printf("%c", ch);
        printf("\n");
    }
    length = (length+1)>>1;
    return n+1-2*length*length;
}
