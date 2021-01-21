#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

PriorityQueue Initialize( int MaxElements ) /* details omitted */
{
    PriorityQueue q = malloc(sizeof(*q));
    q->Elements = malloc(sizeof(ElementType)*(MaxElements+1));
    q->Capacity = MaxElements;
    q->Size = 0;
    return q;
}
/* Your function will be put here */
void PercolateUp( int p, PriorityQueue H )
{
    ElementType e;
    int parents = p / 2;
    if(parents == 0) {
        return ;
    }
    if(H->Elements[parents] > H->Elements[p]) {
        e = H->Elements[parents];
        H->Elements[parents] = H->Elements[p];
        H->Elements[p] = e;
        PercolateUp(parents, H);
    }
}
void PercolateDown( int p, PriorityQueue H )
{
    ElementType e;
    int left, right, min;
    left = 2 *p;
    right = left + 1;
    if(left > H->Size) {
        return ;
    }
    if(right > H->Size) {
        min = left;
    } else {
        if(H->Elements[right] < H->Elements[left]) {
            min = right;
        } else {
            min = left;
        }
    }
    e = H->Elements[p];
    if(e > H->Elements[min]) {
        H->Elements[p] = H->Elements[min];
        H->Elements[min] = e;
        PercolateDown(min, H);
    }
}