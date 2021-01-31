#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Edge {
    int src;
    int dst;
    int cost;
};

vector<int> com;
vector<bool> visited;
int component;

void DFS(vector<list<Edge>> &G, int v)
{
    if(visited[v]) return ;
    visited[v] = true;
    com[v] = component;
    for(auto &x : G[v]) {
        DFS(G, x.dst);
    } 
}

int main()
{
    int N;
    cin >> N;
    list<Edge> edge;
    vector<list<Edge>> adj(N+1);
    for(int i = 0; i < N*(N-1)/2; i++) {
        int src, dst, cost, build;
        cin >> src >> dst >> cost >> build;
        if(build == 1) {
            adj[src].push_back({src, dst, cost});
            adj[dst].push_back({dst, src, cost});
        } else {
            auto next = edge.begin();
            for(; next != edge.end(); next++) {
                if(cost <= next->cost) break;
            }
            edge.insert(next, {src, dst, cost});
        }
    }
    com.resize(N+1);
    visited.resize(N+1);
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            ++component;
            DFS(adj, i);
        }
    }
    int cost = 0;
    if(component > 1) {
        for(auto &x: edge) {
            if(com[x.src] != com[x.dst]) {
                cost += x.cost;
                int Max = max(com[x.src], com[x.dst]);
                int Min = min(com[x.src], com[x.dst]);
                for(auto &y : com) {
                    if(y == Max) y = Min;
                }
            }
        }
    }
    cout << cost << endl;
    return 0;
}