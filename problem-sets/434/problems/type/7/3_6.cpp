#include <iostream>
using namespace std;

typedef struct Fator_t {
    int co;
    int exp;
    bool valid;
} Factor;

class Polynomial {
public:
    Factor *data;
    int max;
    int min;
    int cnt;
    Polynomial() {
        int n;
        cin >> n;
        this->data = new Factor[n];
        this->cnt = n;
        for (int i = 0; i < n; i++) {
            cin >> this->data[i].co;
            cin >> this->data[i].exp;
            if(i == 0) this->max = this->data[i].exp;
            if(i == n-1) this->min = this->data[i].exp;
        }
    }
    ~Polynomial();
};

int main()
{
    Polynomial *p = new Polynomial();
    Polynomial *q = new Polynomial();
    int max = p->max + q->max;
    int min = p->min + q->min;
    Factor *f = new Factor[max-min+1];
    for(int i = 0; i < max-min+1; i++) {f[i].valid = false; f[i].co = 0;}
    for(int i = 0; i < p->cnt; i++) {
        int coi = p->data[i].co;
        int expi = p->data[i].exp;
        for(int k = 0; k < q->cnt; k++) {
            int cok = q->data[k].co;
            int expk = q->data[k].exp;
            if(!f[max-expi-expk].valid) {
                f[max-expi-expk].valid = true;
                f[max-expi-expk].exp = expi + expk;
            }
            f[max-expi-expk].co += coi * cok;
        }
    }
    bool first = true;
    bool none = true;
    for(int i = 0; i < max-min+1; i++) {
        if(f[i].valid && f[i].co != 0) {
            if(first) {first = false; none = false;} 
            else cout << ' ';
            cout << f[i].co << ' ' << f[i].exp;
        }
    }
    if(none) cout << "0 0";
    cout << endl;
    
    Factor *g = new Factor[p->cnt+q->cnt];
    for(int i = 0; i < p->cnt+q->cnt; i++) {f[i].co = 0;}
    int a = 0;
    int b = 0;
    int c = 0;
    while(a < p->cnt && b < q->cnt) {
        if(p->data[a].exp > q->data[b].exp) {
            g[c].exp = p->data[a].exp;
            g[c].co += p->data[a].co;
            a++;
        } else if(p->data[a].exp < q->data[b].exp) {
            g[c].exp = q->data[b].exp;
            g[c].co += q->data[b].co;
            b++;
        } else {
            g[c].exp = p->data[a].exp;
            g[c].co += p->data[a].co + q->data[b].co;
            a++;
            b++;
        }
        c++;
    }
    while(a < p->cnt) {
        g[c].exp = p->data[a].exp;
        g[c++].co = p->data[a++].co;
    }
    while(b < q->cnt) {
        g[c].exp = q->data[b].exp;
        g[c++].co = q->data[b++].co;
    }
    first = true;
    none = true;
    for(int i = 0; i < p->cnt+q->cnt; i++) {
        if(g[i].co != 0) {
            if(first) {first = false; none = false;} 
            else cout << ' ';
            cout << g[i].co << ' ' << g[i].exp;
        }
    }
    if(none) cout << "0 0";
    cout << endl;
}
