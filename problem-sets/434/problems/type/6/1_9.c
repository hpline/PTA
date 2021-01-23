#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {false, true} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
bool Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;

    L = ReadInput();
    scanf("%d", &X);
    if ( Insert( L, X ) == false )
        printf("Insertion failed.\n");
    PrintList( L );

    return 0;
}

List ReadInput()
{
    List L = malloc(sizeof(*L));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->Data[i]);
    }
    L->Last = n - 1;
    return L;
}

void PrintList( List L )
{
    for (int i = 0; i < L->Last; i++) {
        printf("%d ", L->Data[i]);
    }
    printf("%d\n", L->Data[L->Last]);
    printf("Last = %d\n", L->Last);
}

/* 你的代码将被嵌在这里 */
bool Insert( List L, ElementType X )
{
    Position begin = 0;
    Position end = L->Last;
    if(end+1 >= MAXSIZE) return false;
    while(begin <= end) {
        Position mid = (begin + end) >> 1;
        if(L->Data[mid] > X) begin = mid + 1;
        else if(L->Data[mid] < X) end = mid - 1;
        else return false;
    }
    end = ++L->Last;
    while(begin < end) {
        L->Data[end] = L->Data[end-1];
        end--;
    }
    L->Data[begin] = X;
    return true;
}