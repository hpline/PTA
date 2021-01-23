#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Read()
{
    int x;
    scanf("%d", &x);
    List L = malloc(sizeof(*L));
    L->Next = NULL;
    List cur = NULL;
    while(x--) {
        List node = malloc(sizeof(*node));
        ElementType data;
        scanf("%d", &data);
        node->Data = data;
        node->Next = NULL;
        if(!cur) {
            L->Next = node;
        } else {
            cur->Next = node;
        }
        cur = node;
    }
    return L;
}
void Print( List L )
{
    while(L->Next) {
        L = L->Next;
        printf("%d ", L->Data);
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */
List Insert( List L, ElementType X )
{
    PtrToNode cur = L;
    PtrToNode node = malloc(sizeof(*node));
    node->Data = X;
    node->Next = NULL;
    while(cur->Next) {
        if(cur->Next->Data >=X) {
            node->Next = cur->Next;
            cur->Next = node;
            return L;
        }
        cur = cur->Next;
    }
    if(L->Next) {
        cur->Next = node;
    } else {
        L->Next = node;
    }
    return L;
}