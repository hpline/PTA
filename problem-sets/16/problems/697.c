#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
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
    }
    return end;
}
void PrintStack( Stack S, int Stacknum )
{
    printf("Pop from Stack %d:", Stacknum);
    if(Stacknum == 1) {
        for(int i = S->Top1-1; i >= 0; i--) {
            printf(" %d ", S->Array[i]);
        }
    } else if(Stacknum == 2) {
        for(int i = S->Top2; i < S->Capacity; i++) {
            printf(" %d ", S->Array[i]);
        }
    }
    printf("\n");
}

/* Your function will be put here */
Stack CreateStack( int MaxElements )
{
    Stack s  = malloc(sizeof(*s));
    s->Array = malloc(sizeof(ElementType)*MaxElements);
    s->Capacity = MaxElements;
    s->Top1 = 0;
    s->Top2 = MaxElements;
    return s;
}
int IsEmpty( Stack S, int Stacknum )
{
    if((Stacknum == 1) && (S->Top1 == 0)) {
        return 1;
    } else if((Stacknum == 2) && (S->Top2 == S->Capacity)) {
        return 1;
    } else {
        return 0;
    }
}
int IsFull( Stack S )
{
    if(S->Top1 == S->Top2) {
        return 1;
    } else {
        return 0;
    }
}
int Push( ElementType X, Stack S, int Stacknum )
{
    if(IsFull(S)) {
        return 0;
    }
    if(Stacknum == 1) {
        S->Array[S->Top1++] = X;
    } else if(Stacknum == 2) {
        S->Array[--S->Top2] = X;
    } else {
        return 0;
    }
    return 1;
}
ElementType Top_Pop( Stack S, int Stacknum )
{
    ElementType elem = ERROR;
    if(IsEmpty(S, Stacknum)) {
        return ERROR;
    }
    if(Stacknum == 1) {
        elem = S->Array[--S->Top1];
    } else if(Stacknum == 2) {
        elem = S->Array[S->Top2++];
    }
    return elem;
}