#include <iostream>
using namespace std;

void reverse(int *p, int b, int e)
{
    while(b < --e) {
        int temp = p[b];
        p[b++] = p[e];
        p[e] = temp;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    m = m % n;
    int *p = new int[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    reverse(p, 0, m);
    reverse(p, m, n);
    reverse(p, 0, n);
    for(int i = 0; i < n-1; i++) cout << p[i] << ' ';
    cout << p[n-1] << endl;
}