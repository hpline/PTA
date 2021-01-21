#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            // done = 1;
            break;
        }
    }
    return 0;
}

#include "string.h"
#define MAXN 20
Operation GetOp()
{
    char str[MAXN];
    scanf("%s", str);
    if(!strcmp(str, "Pop")) {
        return pop;
    } else if(!strcmp(str, "Push")) {
        return push;
    } else if(!strcmp(str, "Eject")) {
        return eject;
    } else if(!strcmp(str, "Inject")) {
        return inject;
    }
    return end;
}
void PrintDeque( Deque D )
{
    PtrToNode node = D->Front;
    if(node == NULL) {
        return ;
    }
    printf("Inside Deque:");
    do {
        printf(" %d ", node->Element);
        node = node->Next;
    } while(node != D->Front);
    printf("\n");

}

/* Your function will be put here */
Deque CreateDeque()
{
    Deque que = malloc(sizeof(*que));
    que->Front = que->Rear = NULL;
    return que;
}
int Push( ElementType X, Deque D )
{
    PtrToNode node = malloc(sizeof(*node));
    if(node == NULL) {
        return 0;
    }
    if(X == ERROR) {
        return 0;
    }
    node->Element = X;
    if(D->Front == NULL) {
        node->Last = node;
        node->Next = node;
        D->Front = node;
        D->Rear = node;
    } else {
        node->Next = D->Front;
        node->Last = D->Front->Last;
        D->Front->Last->Next = node;
        D->Front->Last = node;
        D->Front = node;
    }
    return 1;
}
ElementType Pop( Deque D )
{
    PtrToNode   node;
    ElementType elem;
    node = D->Front;
    if(node == NULL) {
        return ERROR;
    }
    elem = node->Element;
    if(D->Front == D->Rear) {
        D->Front = D->Rear = NULL;
        free(node);
    } else {
        node->Last->Next = node->Next;
        node->Next->Last = node->Last;
        D->Front = node->Next;
        free(node);
    }
    return elem;
}
int Inject( ElementType X, Deque D )
{
    PtrToNode node = malloc(sizeof(*node));
    if(node == NULL) {
        return 0;
    }
    if(X == ERROR) {
        return 0;
    }
    node->Element = X;
    if(D->Rear == NULL) {
        node->Last = node;
        node->Next = node;
        D->Front = node;
        D->Rear = node;
    } else {
        node->Next = D->Rear->Next;
        node->Last = D->Rear;
        D->Rear->Next->Last = node;
        D->Rear->Next = node;
        D->Rear = node;
    }
    return 1;
}
ElementType Eject( Deque D )
{
    PtrToNode   node;
    ElementType elem;
    node = D->Rear;
    if(node == NULL) {
        return ERROR;
    }
    elem = node->Element;
    if(D->Front == D->Rear) {
        D->Front = D->Rear = NULL;
        free(node);
    } else {
        node->Last->Next = node->Next;
        node->Next->Last = node->Last;
        D->Rear = node->Last;
        free(node);
    }
    return elem;
}