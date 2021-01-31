#include <iostream>
#include <cstring>

using namespace std;
#define MaxSize  32

void print(char *b, char *e)
{
    static int space = 0;
    if(b == NULL) return ;
    if(space) cout << ' ';
    else space = 1;
    while(b < e) cout << *(b++);
}

int main() 
{
    char str[MaxSize];
    cin >> str;
    char stack[MaxSize];
    int  top = 0;
    char *p = str;
    char *operand = NULL;
    while(1) {
        char ch = *p;
        if(ch == '\0') {
            print(operand, p);
            while(top) cout << ' ' << stack[--top];
            break;
        } else {
            if(strchr("+-*/()", ch)) {
                if(ch == '(') { 
                    stack[top++] = ch;
                } else if(ch == ')') {
                    print(operand, p);
                    operand = NULL;
                    while(top && stack[top-1] != '(') 
                        cout << ' ' << stack[--top];
                    if(top) --top;
                } else if(ch == '*' || ch == '/') {
                    print(operand, p);
                    operand = NULL;
                    while(top && (stack[top-1] == '*' || stack[top-1] == '/'))
                        cout << ' ' << stack[--top];
                    stack[top++] = ch;
                } else if(ch == '+' || ch == '-') {
                    if(p == str || ( strchr("+-*/(", p[-1]) )) {
                        if(operand == NULL) operand = p;
                    } else {
                        print(operand, p);
                        operand = NULL;
                        while(top && (stack[top-1] != '('))
                            cout << ' ' << stack[--top];
                        stack[top++] = ch;
                    }
                }
            } else if(operand == NULL) operand = p;
        }
        p++;
    }
    return 0;
}