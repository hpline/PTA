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

void ShortestDist( LGraph Graph, int dist[], Vertex S );

int main()
{
    int dist[MaxVertexNum];
    Vertex S, V;
    LGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);

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
void ShortestDist( LGraph Graph, int dist[], Vertex S )
{
    bool visited[MaxVertexNum];
    for(int i = 0; i < Graph->Nv; i++) {
        dist[i] = -1;
        visited[i] = false;
    }
    dist[S] = 0;
    for(int i = 0; i < Graph->Nv; i++) {
        PtrToAdjVNode node;
        int min = -1;
        for(int j = 0; j < Graph->Nv; j++) {
            if(!visited[j] && dist[j] != -1) {
                if(min == -1 || dist[min] > dist[j]) {
                    min = j;
                }
            }
        }
        if(min == -1) break;
        visited[min] = true;
        node = Graph->G[min].FirstEdge;
        while(node) {
            if(!visited[node->AdjV] && dist[node->AdjV] == -1) {
                dist[node->AdjV] = dist[min] + 1;
            }
            node = node->Next;
        }
    }
}