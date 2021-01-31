#include <iostream>
using namespace std;

int main()
{
    int ans;
    cin >> ans;
    char op;
    cin >> op;
    while(op != '=') {
        int num;
        cin >> num;
        switch (op){
        case '+': ans += num; break;
        case '-': ans -= num; break;
        case '*': ans *= num; break;
        case '/': 
            if(num == 0) {
                cout << "ERROR" << endl;
                return 0;
            }
            ans /= num; 
            break;
        default:
            cout << "ERROR" << endl;
            return 0;
        }
        cin >> op;
    }
    cout << ans << endl;
    return 0;
}