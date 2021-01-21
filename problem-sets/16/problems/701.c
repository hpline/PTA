#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}

void Level_order ( Tree T, void (*visit)(Tree ThisNode) );

int main()
{
    Tree T = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}
Tree _BuildTree(ElementType x)
{
    Tree T = malloc(sizeof(*T));
    T->Element = x;
    T->Left = NULL;
    T->Right = NULL;
}
Tree BuildTree()
{
    Tree t1 = _BuildTree(1);
    Tree t2 = _BuildTree(2);
    Tree t3 = _BuildTree(3);
    Tree t4 = _BuildTree(4);
    Tree t5 = _BuildTree(5);
    Tree t6 = _BuildTree(6);
    Tree t7 = _BuildTree(7);
    t1->Left = t2;
    t1->Right = t3;
    t2->Left = t4;
    t2->Right = t5;
    t3->Left = t6;
    t3->Right = t7;
    return t1;
}

/* Your function will be put here */
void Level_order ( Tree T, void (*visit)(Tree ThisNode) )
{
    Tree Q[MaxTree];
    int front = 0, rear = 0;
    if(T) Q[rear++] = T;
    while(front < rear) {
        T = Q[front++];
        visit(T);
        if(T->Left)  Q[rear++] = T->Left;
        if(T->Right) Q[rear++] = T->Right;
    }
}