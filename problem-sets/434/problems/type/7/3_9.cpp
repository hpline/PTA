#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    string str;
    getline(cin, str);
    while(n--) {
        int top = 0;
        getline(cin, str);
        int i = 0;
        while(i < str.size()) {
            if(str[i] == 'S') {
                if(top >= m) break;
                else top++;
            } else if(str[i] == 'X') {
                if(top == 0) break;
                else top--;
            }
            i++;
        }
        if(i == str.size() && !top) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}