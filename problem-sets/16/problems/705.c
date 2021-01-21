#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG()
{
    int v, e;
    Graph g = malloc(sizeof(*g));
    scanf("%d", &v);
    scanf("%d", &e);
    g->Array = malloc(sizeof(*g->Array)*v);
    g->NumOfVertices = v;
    g->NumOfEdges = e;
    for(int i = 0; i < v; i++) {
        g->Array[i] = NULL;
    }
    for(int i = 0; i < e; i++) {
        int src, dest;
        PtrToVNode edge = malloc(sizeof(*edge));
        scanf("%d", &src);
        scanf("%d", &dest);
        edge->Vert = dest;
        edge->Next = g->Array[src];
        g->Array[src] = edge;
    }
    return g;
}
void PrintG( Graph G )
{
    for(int i = 0; i < G->NumOfVertices; i++) {
        PtrToVNode node = G->Array[i];
        printf("%d ", i);
        while(node) {
            printf("%d ", node->Vert);
            node = node->Next;
        }
        printf("\n");
    }
}

void PrintV( Vertex V )
{
   printf("%d ", V);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents( G, PrintV );
    return 0;
}

/* Your function will be put here */
Vertex aux1[MaxVertices];
int top1 = -1;
Vertex aux2[MaxVertices];
int top2 = -1;
int detect[MaxVertices];
int connected[MaxVertices];
int time = 0;

void Gabow( Graph G, Vertex v, void (*visit)(Vertex V) )
{
    PtrToVNode node;
    detect[v] = ++time;
    aux1[++top1] = v;
    aux2[++top2] = v;
    node = G->Array[v];
    while(node) {
        Vertex adj = node->Vert;
        if(!detect[adj]) {
            Gabow(G, adj, visit);
        } else if(!connected[adj]) {
            Vertex com = aux1[top1];
            while(detect[com] > detect[adj]) {
                com = aux1[--top1];
            }
        }
        node = node->Next;
    }
    if(aux1[top1] == v) {
        top1--;
        do {
            visit(aux2[top2]);
            connected[aux2[top2]] = 1;
        } while(aux2[top2--] != v);
        printf("\n");
    }
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) )
{
    for(Vertex i = 0; i < G->NumOfVertices; i++) {
        detect[i] = connected[i] = 0;
    }
    for(Vertex i = 0; i < G->NumOfVertices; i++) {
        if(detect[i] == 0) Gabow(G, i, visit);
    }
}