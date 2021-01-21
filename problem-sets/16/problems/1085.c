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

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S );

int main()
{
    int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, count, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", count[V]);
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
int DFS ( MGraph Graph, Vertex S, Vertex D, int dist )
{
    int ret = 0;
    if(dist >= 0) {
        if(S == D) {
            if(dist == 0) ret = 1;
        } else {
            for(int i = 0; i < Graph->Nv; i++) {
                if(S != i && dist-Graph->G[S][i] >= 0) {
                    ret += DFS(Graph, i, D, dist-Graph->G[S][i]);
                }
            }
        }
    }
    return ret;
}

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S )
{
    int visited[MaxVertexNum];
    for (int i = 0; i < MaxVertexNum; i++) {
        dist[i] = -1;
        count[i] = 0;
        visited[i] = false;
    }
    dist[S] = 0;
    for(int i = 0; i < Graph->Nv; i++) {
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
        for(int j = 0; j < Graph->Nv; j++) {
            if(min != j && Graph->G[min][j] < INFINITY) {
                if(dist[j] == -1 || (dist[j] > dist[min] + Graph->G[min][j])) {
                    dist[j] = dist[min] + Graph->G[min][j];
                }
            }
        }
    }
    for(int i = 0; i < Graph->Nv; i++) {
        count[i] = DFS(Graph, S, i, dist[i]);
    }
}