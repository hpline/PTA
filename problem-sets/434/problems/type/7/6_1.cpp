#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>

using namespace std;

#define MaxVertexNum  1008
typedef int WeightType;
typedef int Vertex;
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode Graph;

Graph ReadG()
{
    Graph G = new GNode;
    cin >> G->Nv >> G->Ne;
    for(int i = 0; i < G->Ne; i++) {
        int s, d;
        cin >> s >> d;
        G->G[s][d] = 1;
        G->G[d][s] = 1;
    }
    return G;
}

deque<Vertex> queue(MaxVertexNum);

double SixDegree(Graph G, Vertex i)
{
    vector<bool> Visited(G->Nv);
    vector<int>  Dist(G->Nv);
    Visited[i] = true;
    Dist[i] = 0;
    queue.push_back(i);
    while(!queue.empty()) {
        i = queue.front();
        queue.pop_front();
        for(Vertex k = 1; k <= G->Nv; k++) {
            if(G->G[i][k] && !Visited[k]) {
                Visited[k] = true;
                Dist[k] = Dist[i]+1;
                if(Dist[k] < 6) queue.push_back(k);
            }
        }
    }
    int cnt = 0;
    for(Vertex k = 1; k <= G->Nv; k++) {
        if(Visited[k]) cnt++;
    }
    return (double)cnt/G->Nv * 100;
}

int main()
{
    Graph G = ReadG();
    for(Vertex i = 1; i <= G->Nv; i++) {
        cout << i << ": " << scientific << fixed << setprecision(2) << SixDegree(G, i) << '%' << endl;
    }
    return 0;
}
