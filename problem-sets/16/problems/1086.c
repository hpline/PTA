#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(); /* details omitted */

void ShortestDist( MGraph Graph, int dist[], int path[], Vertex S );

int main()
{
    int dist[MaxVertexNum], path[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, path, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", path[V]);
    printf("\n");

    return 0;
}
MGraph ReadG()
{
    int v, e;
    MGraph g = malloc(sizeof(*g));
    scanf("%d", &v);
    scanf("%d", &e);
    g->Nv = v;
    g->Ne = e;
    for(int i = 0; i < MaxVertexNum; i++) {
        for(int j = 0; j < MaxVertexNum; j++) {
            g->G[i][j] = INFINITY;
        }
    }
    for(int i = 0; i < e; i++) {
        int src, dest, weight;
        scanf("%d", &src);
        scanf("%d", &dest);
        scanf("%d", &weight);
        g->G[src][dest] = weight;
    }
    return g;
}
void PrintG( MGraph G )
{
    for(int i = 0; i < G->Nv; i++) {
        for(int j = 0; j < G->Nv; j++) {
            if(G->G[i][j] < INFINITY) {
                printf("%d %d %d\n", i, j, G->G[i][j]);
            }
        }
    }
}

/* Your function will be put here */
void ShortestDist( MGraph Graph, int dist[], int path[], Vertex S )
{
    int visited[MaxVertexNum];
    for(int i = 0; i < Graph->Nv; i++) {
        dist[i] = path[i] = -1;
        visited[i] = false;
    }
    dist[S] = 0;
    path[S] = -1;
    for(int i = 0; i < Graph->Nv; i++) {
        int min = -1;
        for(int k = 0; k < Graph->Nv; k++) {
            if(!visited[k] && (dist[k] > -1)) {
                if((min == -1) || (dist[k] < dist[min])) {
                    min = k;
                }
            }
        }
        if(min == -1) return ;
        visited[min] = true;
        for(int i = 0; i < Graph->Nv; i++) {
            if(Graph->G[min][i] < INFINITY) {
                if((dist[i] == -1) || (dist[i]>Graph->G[min][i]+dist[min])) {
                    dist[i] = Graph->G[min][i] + dist[min];
                    path[i] = min;
                }
            }
        }
    }
}