#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
} 


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

/* Your function will be put here */
void merge_pass( ElementType list[], ElementType sorted[], int N, int length )
{
    for (int i = 0; i < N;) {
        int e1 = i, e2 = i + length;
        int end1 = e2 < N ? e2 : N;
        int end2 = (e2 + length) < N ? (e2 + length) : N; 
        while(e1 < end1 && e2 < end2) 
            sorted[i++] = list[e1] <= list[e2] ? list[e1++] : list[e2++];
        while(e1 < end1) sorted[i++] = list[e1++];
        while(e2 < end2) sorted[i++] = list[e2++];
        i = end2;
    }
}