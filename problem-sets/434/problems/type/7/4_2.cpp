#include <iostream>
#include <vector>
using namespace std;

typedef int ElemType;
typedef struct TreeNode {
    struct TreeNode *Left;
    struct TreeNode *Right;
    ElemType Elem;
    int      Height;
} *Tree;

typedef struct AVLTree {
    Tree T;
} *AVL;

AVL Init()
{
    AVL t = new AVLTree;
    t->T = NULL;
    return t;
}

int Height(Tree T)
{
    if(T == NULL) return 0;
    return T->Height; 
}

void UpdateHeight(Tree T)
{
    if(T != NULL) T->Height = max(Height(T->Left), Height(T->Right)) + 1;
}

int Weight(Tree T)
{
    return Height(T->Left) - Height(T->Right);
}

void Insert(Tree &T, Tree &n)
{
    if(T == NULL) {
        T = n;
    } else if(T->Elem > n->Elem) {
        Insert(T->Left, n);
        if(Weight(T) >= 2) {
            if(Weight(T->Left) == 1) {
                Tree root = T->Left;
                T->Left = root->Right;
                root->Right = T;
                UpdateHeight(root->Right);
                T = root;
            } else if(Weight(T->Left) == -1) {
                Tree root = T->Left->Right;
                T->Left->Right = root->Left;
                root->Left = T->Left;
                T->Left = root->Right;
                root->Right = T;
                UpdateHeight(root->Left);
                UpdateHeight(root->Right);
                T = root;
            }
        }
    } else {
        Insert(T->Right, n);
        if(Weight(T) <= -2) {
            if(Weight(T->Right) == -1) {
                Tree root = T->Right;
                T->Right = root->Left;
                root->Left = T;
                UpdateHeight(root->Left);
                T = root;
            } else if(Weight(T->Right) == 1) {
                Tree root = T->Right->Left;
                T->Right->Left = root->Right;
                root->Right = T->Right;
                T->Right = root->Left;
                root->Left = T;
                UpdateHeight(root->Left);
                UpdateHeight(root->Right);
                T = root;
            }
        }
    }
    UpdateHeight(T);
}

void Add(AVL T, ElemType elem)
{
    Tree t = new TreeNode;
    t->Elem = elem;
    t->Left = NULL;
    t->Right = NULL;
    t->Height = 0;
    Insert(T->T, t);
}

int main()
{
    AVL T = Init();
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        ElemType x;
        cin >> x;
        Add(T, x);
    }
    cout << T->T->Elem << endl;
    return 0;
}