#include <iostream>

using namespace std;

#define MAXNUM   9

int output[MAXNUM];
int cnt = 0;
bool visited[MAXNUM+1];
int N = 0;

void Permitation()
{
    int i = 1;
    while(i <= N) {
        if(!visited[i]) {
            visited[i] = true;
            output[cnt++]= i;
            if(cnt == N) {
                for(int i = 0; i < cnt; i++) cout << output[i];
                cout << endl;
            } else Permitation();
            cnt--;
            visited[i] = false;
        }
        i++;
    }
}

int main()
{
    cin >> N;
    Permitation();
}