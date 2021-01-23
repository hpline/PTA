#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}

BinTree Create( ElementType X )
{
    BinTree T = malloc(sizeof(*T));
    T->Data = X;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}
BinTree BuildTree()
{
    int x;
    scanf("%d", &x);
    if(x == 0) return NULL;
    BinTree T = Create(x);
    T->Left = BuildTree();
    T->Right = BuildTree(); 
    return T;
}

/* 你的代码将被嵌在这里 */
#include <limits.h>
bool InOrder( BinTree T, ElementType *ans )
{
    if(!T) return true;
    if(InOrder(T->Left, ans))
        if(*ans <= T->Data) {
            *ans = T->Data;
            return InOrder(T->Right, ans);
        }
    return false;
}
bool IsBST ( BinTree T )
{
    ElementType ans = INT_MIN;
    return InOrder(T, &ans);
}