#include <iostream>
using namespace std;

int main()
{
    int a, n;
    cin >> a >> n;
    int *s = new int[n+1];
    for(int i = n; i > 0; i--) {
        int ans = i * a + s[i];
        s[i] = 0;
        for(int k = i; ans > 0; k--) {
            s[k] += ans % 10;
            ans /= 10;
        }
    }
    if(n == 0 || s[0]) cout << s[0];
    for(int i = 1; i < n+1; i++) cout << s[i];
    cout << endl;    
}