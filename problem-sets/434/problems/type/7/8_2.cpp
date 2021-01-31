#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct CustomerType {
    int arrive;
    int process;
    int vip;
} *Customer;

typedef struct WindowType {
    int sum;
    int final;
    bool operator <(const WindowType &w) {
        return final < w.final;
    }
} *Window;

int main()
{
    int N;
    cin >> N;
    vector<CustomerType> c(N);
    vector<int>  used(N);
    for(int i = 0; i < N; i++) {
        cin >> c[i].arrive >> c[i].process >> c[i].vip;
        c[i].process = min(c[i].process, 60);
    }
    int K, vip;
    cin >> K >> vip;
    vector<WindowType> w(K);

    for(int i = 0; i < N; i++) {
        for(int h = 0; h < K; h++) {
            if(w[h].final < c.front().arrive) {
                w[h].final = c.front().arrive;
            }
        }
        int idle = 0;
        for(int h = 0; h < K; h++) {
            if(w[h].final < w[idle].final) {
                idle = h;
            } 
        }

        auto current = c.begin();
        for(auto cur = current; cur != c.end(); cur++) {
            if(cur->arrive > w[idle].final) break;
            else if(cur->vip) {
                if(w[vip].final == w[idle].final) {
                    current = cur;
                    idle = vip;
                }
                break;
            }
        }

        used[i] = w[idle].final - current->arrive;
        w[idle].sum++;
        w[idle].final += current->process;
        c.erase(current);
    }

    int longest = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += used[i];
        if(used[i] > longest) longest = used[i];
    }
    auto latest = max_element(w.begin(), w.end());
    printf("%.1f %d %d\n", (double)sum/N, longest, latest->final);
    
    for(int h = 0; h < K; h++) {
        cout << (h == 0 ? "" : " ") << w[h].sum;
    }
    return 0;
}