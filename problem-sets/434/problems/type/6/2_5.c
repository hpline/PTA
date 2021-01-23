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
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
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
    if(!L->Next) printf("NULL");
    while(L->Next) {
        L = L->Next;
        printf("%d ", L->Data);
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    List head = malloc(sizeof(*head));
    PtrToNode *cur = &head->Next;
    PtrToNode  p1 = L1->Next;
    PtrToNode  p2 = L2->Next;
    while(p1 && p2) {
        if(p1->Data <= p2->Data) {
            *cur = p1;
            p1 = p1->Next;
        } else {
            *cur = p2;
            p2 = p2->Next;
        }
        cur = &((*cur)->Next);
    }
    if(p1) *cur = p1;
    if(p2) *cur = p2;
    L1->Next = L2->Next = NULL;
    return head;
}