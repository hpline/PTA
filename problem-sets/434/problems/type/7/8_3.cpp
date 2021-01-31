#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

struct Customer {
    string name;
    int    T;
    int    P;
    int    id;
};

unordered_map<string, int> circle;
list<Customer> customer;
vector<int> wait;

int main()
{
    int N, M;
    cin >> N >> M;
    circle.reserve(N);
    for (int i = 0; i < M; i++) {
        string name;
        int L;
        cin >> L;
        for(int j = 0; j < L; j++) {
            cin >> name;
            circle.insert({name, i+1});
        }
    }
    wait.resize(N);
    for(int i = 0; i < N; i++) {
        Customer user;
        cin >> user.name >> user.T >> user.P;
        user.id = circle[user.name];
        customer.push_back(user);
    }
    int last_finish = 0;
    for(int i = 0; i < N;) {
        Customer c = customer.front();
        int id = c.id;
        if(last_finish < c.T) last_finish = c.T;
        if(id == 0) {
            wait[i++] = last_finish - c.T;
            last_finish += min(c.P, 60);
            cout << c.name << endl;
            customer.pop_front();
        } else {
            for(auto x = customer.begin(); x != customer.end(); ++x) {
                if(x->T > last_finish) break;
                if(x->id != id) continue;
                wait[i++] = last_finish - x->T;
                last_finish += min(x->P, 60);
                cout << x->name << endl;
                x = customer.erase(x);
                --x;
            }
        }
    }
    double sum = 0;
    for(auto &x : wait) sum += x;
    printf("%.1f\n", sum/N);
    return 0;
}