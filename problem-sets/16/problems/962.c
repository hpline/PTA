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

int CountConnectedComponents( LGraph Graph );

int main()
{
    LGraph G = ReadG();
    printf("%d\n", CountConnectedComponents(G));

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
        PtrToAdjVNode edge2 = malloc(sizeof(*edge2));
        edge2->AdjV = src;
        edge2->Next = g->G[dest].FirstEdge;
        g->G[dest].FirstEdge = edge2;
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
static int visited[MaxVertexNum];
void DFS( LGraph Graph, Vertex v)
{
    PtrToAdjVNode node;
    if(visited[v]) return ;
    visited[v] = true;
    node = Graph->G[v].FirstEdge;
    while(node) {
        DFS(Graph, node->AdjV);
        node = node->Next;
    }
}
int CountConnectedComponents( LGraph Graph )
{
    int count = 0;
    for(int i = 0; i < Graph->Nv; i++) visited[i] = false;
    for(int i = 0; i < Graph->Nv; i++) {
        if(!visited[i]) {
            DFS(Graph, i);
            count++;
        }
    }
    return count;
}