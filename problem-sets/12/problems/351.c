#include <stdio.h>
#include <math.h>

int search( int n );

int main()
{
    int number;

    scanf("%d",&number);
    printf("count=%d\n",search(number));

    return 0;
}


/* 你的代码将被嵌在这里 */
int search( int n )
{
    int i1, i2, i3;
    int i = 11;
    int doub = i * i;;
    int count = 0;
     while(doub <= n) {
        i1 = doub % 10;
        i2 = doub/10 % 10;
        i3 = doub/100 % 10;
        if(i1 == i2) {
            count++;
        } else if(i1 == i3) {
            count++;
        } else if(i2 == i3) {
            count++;
        }
        i++;
        doub = i * i;
    };
    return count;
}