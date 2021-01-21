#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool TopSort( LGraph Graph, Vertex TopOrder[] );

int main()
{
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();

    if ( TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

    return 0;
}
LGraph ReadG()
{
    int v, e;
    LGraph g = malloc(sizeof(*g));
    scanf("%d", &v);
    scanf("%d", &e);
    g->Nv = v;
    g->Ne = e;
    for(int i = 0; i < v; i++) {
        g->G[i].FirstEdge = NULL;
    }
    for(int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d", &src);
        scanf("%d", &dest);
        PtrToAdjVNode edge = malloc(sizeof(*edge));
        edge->AdjV = dest;
        edge->Next = g->G[src].FirstEdge;
        g->G[src].FirstEdge = edge;
    }
    return g;
}
void PrintG( LGraph G )
{
    for(int i = 0; i < G->Nv; i++) {
        PtrToAdjVNode node = G->G[i].FirstEdge;
        printf("%d ", i);
        while(node) {
            printf("%d ", node->AdjV);
            node = node->Next;
        }
        printf("\n");
    }
}

/* Your function will be put here */
bool TopSort( LGraph Graph, Vertex TopOrder[] )
{
    Vertex stack[MaxVertexNum];
    int prior[MaxVertexNum];
    int top = -1;
    for(Vertex i = 0; i < Graph->Nv; i++) {
        prior[i] = 0;
    }
    for(Vertex i = 0; i < Graph->Nv; i++) {
        PtrToAdjVNode node;
        node = Graph->G[i].FirstEdge;
        while(node) {
            prior[node->AdjV]++;
            node = node->Next;
        }
    }
    for(Vertex i = 0; i < Graph->Nv; i++) {
        if(prior[i] == 0) stack[++top] = i;
    }
    for(Vertex i = 0; i < Graph->Nv; i++) {
        PtrToAdjVNode node;
        Vertex v;
        if(top < 0) return false;
        v = stack[top--];
        *(TopOrder++) = v;
        node = Graph->G[v].FirstEdge;
        while(node) {
            if((--prior[node->AdjV]) == 0) stack[++top] = node->AdjV;
            node = node->Next;
        }
    }
    return true;
}