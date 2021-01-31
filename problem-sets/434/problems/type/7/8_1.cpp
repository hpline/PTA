#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct CustomerType {
    int arrive;
    int used;
    int wait;
} *Customer;

typedef struct WindowType {
    int sum;
    int final;
} *Window;


int main()
{
    int N;
    cin >> N;
    Customer c = new CustomerType[N];
    for(int i = 0; i < N; i++) {
        cin >> c[i].arrive >> c[i].used;
        if(c[i].used > 60) c[i].used = 60;
    }
    int K;
    cin >> K;
    Window w = new WindowType[K];
    for(int i = 0; i < K; i++) w[i].final = 0;
    for(int i = 0; i < N; i++) {
        for(int h = 0; h < K; h++) {
            if(w[h].final < c[i].arrive) {
                w[h].final = c[i].arrive;
            }
        }
        int idle = 0;
        int minvalue = w[idle].final;
        for(int h = 1; h < K; h++) {
            if(w[h].final < minvalue) {
                idle = h;
                minvalue = w[h].final;
            }
        }
        w[idle].sum++;
        c[i].wait = w[idle].final - c[i].arrive;
        w[idle].final = w[idle].final + c[i].used;
    }
    int maxvalue = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += c[i].wait;
        if(c[i].wait > maxvalue) maxvalue = c[i].wait;
    }
    printf("%.1f %d", (double)sum/N, maxvalue);
    maxvalue = 0;
    for(int h = 0; h < K; h++) {
        if(w[h].final > maxvalue) maxvalue = w[h].final;
    }
    cout << ' ' << maxvalue << endl;
    bool space = false;
    for(int h = 0; h < K; h++) {
        if(!space) space = true;
        else cout << ' ';
        cout << w[h].sum;
    }
    delete[] w;
    delete[] c;
    return 0;
}