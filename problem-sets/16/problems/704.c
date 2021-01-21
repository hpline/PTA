#include <stdio.h>
#include <stdlib.h>

typedef enum { true, false, maybe } Keys;
typedef Keys ElementType;

void Read( ElementType A[], int N ); /* details omitted */

void MySort( ElementType A[], int N );

void PrintA( ElementType A[], int N )
{
    int i, k;

    k = i = 0;
    for ( ; i<N && A[i]==false; i++ );
    if ( i > k )
        printf("false in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==maybe; i++ );
    if ( i > k )
        printf("maybe in A[%d]-A[%d]\n", k, i-1);
    k = i;
    for ( ; i<N && A[i]==true; i++ );
    if ( i > k )
        printf("true in A[%d]-A[%d]\n", k, i-1);
    if ( i < N )
        printf("Wrong Answer\n");
}

int main()
{
    int N;
    ElementType *A;

    scanf("%d", &N);
    A = (ElementType *)malloc(N * sizeof(ElementType));
    Read( A, N );
    MySort( A, N );
    PrintA( A, N );
    return 0;
}
void Read( ElementType A[], int N )
{
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        A[i] = x;
    }
}

/* Your function will be put here */
void MySort( ElementType A[], int N )
{
    ElementType e;
    int i, j;
    if(N <= 1) {
        return ;
    }
    for(i = 0, j = N - 1; i < j; i++, j--) {
        while(i < j) {
            if(A[i] != false) break;
            else ++i;
        }
        while(i < j) {
            if(A[j] == false) break;
            else --j;
        }
        e = A[i];
        A[i] = A[j];
        A[j] = e;
    }
    for(i = 0, j = N - 1; i < j; i++, j--) {
        while(i < j) {
            if(A[i] == true) break;
            else ++i;
        }
        while(i < j) {
            if(A[j] != true) break;
            else --j;
        }
        e = A[i];
        A[i] = A[j];
        A[j] = e;
    }
}