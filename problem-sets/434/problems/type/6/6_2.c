#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} bool;
#define MaxVertexNum 10   /* 最大顶点数设为10 */
typedef int Vertex;       /* 用顶点下标表示顶点,为整型 */

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}

LGraph CreateGraph()
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
    for(Vertex i = 0; i < MaxVertexNum; i++) Visited[i] = false;
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

/* 你的代码将被嵌在这里 */
#define VISIT(v)    Visit(v);Visited[v] = true
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    Vertex Q[MaxVertexNum];
    int front = 0, rear = 0;
    Q[rear++] = S;
    VISIT(S);
    while(front < rear) {
        Vertex v = Q[front++];
        PtrToAdjVNode node = Graph->G[v].FirstEdge;
        while(node) {
            if(!Visited[node->AdjV]) {
                Q[rear++] = node->AdjV;
                VISIT(node->AdjV);
            }
            node = node->Next;
        }
    }
}