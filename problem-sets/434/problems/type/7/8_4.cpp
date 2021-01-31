#include <iostream>
#include <climits>
#include <vector>
#include <list>

using namespace std;

typedef int Vertex;
struct Edge {
    Vertex adj;
    int cost;
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<list<Edge>> Graph(N+1);
    for(int i = 0; i < M; i++) {
        Vertex src, dst;
        int cost;
        cin >> src >> dst >> cost;
        auto next = Graph[src].begin();
        for(; next != Graph[src].end(); next++) {
            if(cost <= next->cost) break;
        }
        Graph[src].insert(next, {dst,cost});
        next = Graph[dst].begin();
        for(; next != Graph[dst].end(); next++) {
            if(cost <= next->cost) break;
        }
        Graph[dst].insert(next, {src,cost});
    }

    vector<bool> Visited(N+1);
    Visited[1] = true;
    int Cost = 0;
    for(int i = 0; i < N-1; i++) {
        Vertex Adj = 0;
        int Min = INT_MAX;
        for(Vertex src = 1; src <= N; src++) {
            if(Visited[src]) {
                auto x = Graph[src].begin();
                for(; x != Graph[src].end(); x++) {
                    if(Visited[x->adj]) {
                        x = Graph[src].erase(x);
                        --x;
                    } else break;
                }
                if(x != Graph[src].end()) {
                    if (Min > x->cost) {
                        Min = x->cost;
                        Adj = x->adj;
                    }
                }
            }
        }
        if(Adj == 0) {
            cout << "Impossible" << endl;
            return 0;
        }
        Cost += Min;
        Visited[Adj] = true;
    }
    cout << Cost << endl;
    return 0;
}