#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> H;
    H.reserve(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> H[i];
        int parent = i / 2;
        int cur = i;
        while(parent) {
            if(H[cur] < H[parent]) {
                swap(H[cur], H[parent]);
                cur = parent;
                parent = cur / 2;
                continue;
            }
            break;
        }
    }
    while (M--) {
        int i;
        cin >> i;
        while(i) {
            cout << H[i];
            if(i == 1) cout << endl;
            else cout << ' ';
            i >>= 1;
        }
    }
    return 0;
}