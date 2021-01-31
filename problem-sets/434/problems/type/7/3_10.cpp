#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef enum {a, b, c} Pillar;
vector<Pillar> pos = {a, b, c};
map<Pillar, vector<int>> disk = {{a,{}}, {b,{}}, {c,{}}};

void swap(Pillar &x, Pillar &y)
{
    Pillar tmp = x; 
    x = y; 
    y = tmp;
}

void move(int x, int y)
{
    char str[] = {'a', 'b', 'c'};
    Pillar small = pos[x];
    Pillar large = pos[y];
    if(disk[small].size() == 0 && disk[large].size() == 0) return ;
    else if(disk[small].size() == 0) swap(small, large);
    else if(disk[large].size() != 0 && disk[small].back() > disk[large].back()) swap(small, large);
    disk[large].push_back(disk[small].back());
    disk[small].pop_back();
    cout << str[small] << " -> " << str[large] << endl;
}

void hanoi(int n)
{   
    for(int i = n; i >= 1; i--) disk[a].push_back(i);
    if(n % 2 == 1) swap(pos[1], pos[2]);
    int Pos = 0;
    while(disk[c].size() < n) {
        int Pos1 = (Pos+1) % 3;
        int Pos2 = (Pos1+1) % 3;
        int Pos3 = (Pos2+1) % 3;
        move(Pos, Pos1);
        move(Pos2, Pos3);
        Pos = Pos1;
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n);
}