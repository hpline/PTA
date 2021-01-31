#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long> List;
    List.reserve(N);
    while(N--) {
        int k;
        cin >> k;
        List.push_back(k); 
    }
    sort(List.begin(), List.end());
    bool space = false;
    for(auto &x : List) {
        if(!space) space = true;
        else cout << ' ';
        cout << x;
    }
    return 0;
}