#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

Polynomial Read()
{
    Polynomial head = malloc(sizeof(*head));
    Polynomial cur = head;
    head->Next = NULL;
    head->Coefficient = 0;
    int X, temp;
    scanf("%d", &X);
    for(int i = 0; i < X; i++) {
        PtrToNode node = malloc(sizeof(*node));
        scanf("%d", &temp);
        node->Coefficient = temp;
        scanf("%d", &temp);
        node->Exponent = temp;
        node->Next = NULL;
        cur->Next = node;
        cur = node;
    }
    return head;
}
void Print( Polynomial p )
{
    PtrToNode node = p->Next;
    while(node) {
        printf("%d %d ", node->Coefficient, node->Exponent);
        node = node->Next;
    }
    printf("\n");
}

/* Your function will be put here */
#include "limits.h"
Polynomial Add( Polynomial a, Polynomial b )
{
    Polynomial head = malloc(sizeof(*head));
    PtrToNode A = a->Next;
    PtrToNode B = b->Next;
    PtrToNode cur = head;
    int Coefficient;
    int Exponent;
    head->Next = NULL;
    head->Coefficient = 0;
    head->Exponent = INT_MAX;
    while(A && B) {
        if(A->Exponent > B->Exponent) {
            Coefficient = A->Coefficient;
            Exponent = A->Exponent;
            A = A->Next;
        } else if(A->Exponent < B->Exponent) {
            Coefficient = B->Coefficient;
            Exponent = B->Exponent;
            B = B->Next; 
        } else {
            Coefficient = A->Coefficient + B->Coefficient;
            Exponent = A->Exponent;
            A = A->Next;
            B = B->Next;            
        }
        if(Coefficient == 0) {
            continue;
        } else {
            PtrToNode node = malloc(sizeof(*node));
            node->Coefficient = Coefficient;
            node->Exponent = Exponent;
            cur->Next = node;
            cur = node;
        }
    }
    if(A || B) {
        PtrToNode TEMP;
        if(A)
            TEMP = A;
        else 
            TEMP = B;
        while(TEMP) {
            PtrToNode node = malloc(sizeof(*node));
            node->Coefficient = TEMP->Coefficient;
            node->Exponent = TEMP->Exponent;
            cur->Next = node;
            cur = node;
            TEMP = TEMP->Next;
        }
    }
    cur->Next = NULL;
    return head;
}