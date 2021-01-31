#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
 
#define CHECK(x) if(H[x]==0) {printf("ERROR: T[%d] is NULL\n", x);return 0;}
#define MARK(x)  {int h=x;while(h){V[h]+=1;h>>=1;}}
 
int main()
{
    int N;
    cin >> N;
    vector<int> H;
    vector<int> V;
    H.reserve(N+1);
    V.reserve(N+1);
    for(int k = 1; k <= N; k++) {
        cin >> H[k];
        V[k] = 0;
    }
    int i, j;
    cin >> i >> j;
    CHECK(i);
    CHECK(j);
    MARK(i);
    MARK(j)
    while(i) {
        if(V[i] == 2) { cout << i << ' ' << H[i] << endl; break;}
        i >>= 1;
    }
    return 0;
}