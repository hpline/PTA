#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */
Tree BuildTree2(); /* details omitted */

int Isomorphic( Tree T1, Tree T2 );

int main()
{
    Tree T1, T2;
    T1 = BuildTree();
    T2 = BuildTree2();
    printf("%d\n", Isomorphic(T1, T2));
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

Tree BuildTree2()
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
    t2->Right = t7;
    t3->Left = t5;
    t3->Right = t6;
    return t1;
}

/* Your function will be put here */
int Isomorphic( Tree T1, Tree T2 )
{
    if(T1 && T2) {
        if(T1->Element == T2->Element) {
            if(Isomorphic(T1->Left, T2->Left)
            && Isomorphic(T1->Right, T2->Right)) {
                    return 1;
            } else if(Isomorphic(T1->Left, T2->Right)
                   && Isomorphic(T1->Right, T2->Left)) {
                    return 1;
            }
        }
    } else if(!T1 && !T2) {
        return 1;
    }
    return 0;
}