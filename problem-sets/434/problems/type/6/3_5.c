#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
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
ElementType Find( List L, int m )
{
    PtrToNode node = L->Next;
    PtrToNode guard = L->Next;
    while(guard && m) {
        guard = guard->Next;
        --m;
    }
    if(m) return ERROR;
    while(guard) {
        node = node->Next;
        guard = guard->Next;
    }
    if(node) return node->Data;
    else return ERROR;
}