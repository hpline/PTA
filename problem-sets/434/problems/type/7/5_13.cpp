#include <iostream>
#include <map>
#include <list>
#include <string>
#include <cstring>
using namespace std;

map<string, int> Read()
{
    map<string, int> Freq{};
    int  top = 0;
    while(1) {
        char word[16];
        char ch;
        cin.get(ch);
        if(isdigit(ch) || isalpha(ch) || ch == '_') {
            if(top < 15) {
                if('A' <= ch && ch <= 'Z') ch += 32;
                word[top++] = ch;
            }
        } else if(top) {
            word[top] = '\0';
            top = 0;
            Freq[word] += 1;
        }
        if(ch == '#') break;
    }
    return Freq;
}

int main()
{
    map<string, int> Freq = Read();
    list<pair<string, int>> Seq{};
    for(auto &x : Freq) {
        auto y = Seq.begin();
        while(y != Seq.end()) {
            if(y->second < x.second) break;
            y++;
        }
        Seq.insert(y, x);
    }
    int cnt = Freq.size() / 10;
    cout << Freq.size() << endl;
    for(auto x = Seq.begin(); x != Seq.end(); x++) {
        if(--cnt < 0) break;
        cout << x->second << ':' << x->first << endl;
    }
    return 0;
}