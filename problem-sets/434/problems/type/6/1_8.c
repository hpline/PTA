#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput()
{
    List L = malloc(sizeof(*L));
    scanf("%d", &L->Last);
    for (int i = 1; i <= L->Last; i++) {
        scanf("%d", &L->Data[i]);
    }
    return L;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X )
{
    Position begin = 1;
    Position end = L->Last;
    while(begin <= end) {
        Position mid = (begin + end) >> 1;
        if(L->Data[mid] > X) end = mid - 1;
        else if(L->Data[mid] < X) begin = mid + 1;
        else return mid;
    }
    return NotFound;
}