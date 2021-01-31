#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    int RealStart;
    int RealCount;
    for(int i = 0; i < n; i++) {
        int start;
        if(i == 0) {
            RealCount = 1;
            RealStart = 0;
            start = 0;
        } else {
            if(i == n-1 || p[i-1] >= p[i]) {
                int count  = i - start + 1;
                if(p[i-1] >= p[i]) count--;
                if(count > RealCount) {
                    RealStart = start;
                    RealCount = count;
                }
                start = i;
            }
        }
    }
    for(int i = 0; i < RealCount-1; i++) 
        cout << p[RealStart+i] << ' ';
    cout << p[RealStart+RealCount-1] << endl;
}