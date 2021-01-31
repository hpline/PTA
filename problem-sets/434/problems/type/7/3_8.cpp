#include <iostream>
#include <cstdio>
using namespace std;
#define MAXSIZE 400

int main()
{
    char stack[MAXSIZE];
    int top = 0;
    bool comment = false;
    bool string = false;
    char ch;
    ch = cin.get();
    while(1) {
        char pop;
        switch (ch) {
        case '.': 
            ch = cin.get(); 
            if(ch == '\r' || ch == '\n') {
                if(comment) cout << "NO" << endl << "/*-?" << endl; 
                else if(top) cout << "NO" << endl << stack[--top] << "-?" << endl;
                else cout << "YES" << endl;
                return 0;
            } else {
                continue;
            } 
            break;
        case '\'':
        case '\"':
            if(string) string = false;
            else string = true;
            break;
        case '(': 
        case '[': 
        case '{': 
            if(!string && !comment) {
                stack[top++] = ch; 
            }
            break;
        case '/': 
            if(!string && !comment) {
                ch = cin.get(); 
                if(ch == '*') {
                    comment = true;
                } else {
                    continue;
                }
            }
            break;
        case '*': 
            if(string) break;
            ch = cin.get();  
            if(ch == '/') {
                if(comment) {
                    comment = false;
                } else {
                    cout << "NO" << endl << "?-*/" << endl; 
                    return 0;
                }
            } else {
                continue;
            }
            break;
        case ')':
        case ']': 
        case '}': 
            if(!string && !comment) {
                if(!top) {cout << "NO" << endl << "?-" << ch << endl; return 0;}
                pop = stack[--top]; 
                if(ch == ')' && pop == '(') break;
                if(ch == ']' && pop == '[') break;
                if(ch == '}' && pop == '{') break;
                cout << "NO" << endl << pop << "-?" << endl; 
                return 0;
            }
            break;
        default:
            break;
        }
        ch = cin.get(); 
    }
}