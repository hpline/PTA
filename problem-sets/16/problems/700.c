#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

char *gets(char e[]) { fgets(e, Max_Expr, stdin); }

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */
#include <string.h>
#define EXIT()     return Infinity
#define INIT(s)    int top = 0
#define PUSH(s,e)  s[top++]=e;
#define POP(s,e)   if(top) e=s[--top]; else EXIT()
#define ISEMPTY(s) top==0
typedef enum {Operator, Operand, Separator} Token;

ElementType EvalPostfix(char *expr)
{
    ElementType stack[Max_Expr];
    Token token = Separator;
    char op = 0;
    INIT(stack);
    while(1) {
        char *begin;
        char ch = *expr;
        if(ch == ' ' || ch == '\0') {
            if(token == Operand) {
                PUSH(stack, atof(begin));
            } else if(token == Operator) {
                ElementType e1, e2;
                POP(stack, e2);
                POP(stack, e1);
                switch (op) {
                case '+': PUSH(stack, e1+e2); break;
                case '-': PUSH(stack, e1-e2); break;
                case '*': PUSH(stack, e1*e2); break;
                case '/': 
                    if(e2==0) EXIT();
                    else PUSH(stack, e1/e2); break;
                default: EXIT(); break;
                }
                op = 0;
            }
            if(ch == '\0') {
                ElementType result;
                POP(stack, result);
                if(ISEMPTY(stack) && !op) return result;
                else EXIT();
            } else token = Separator;
        } else if(strchr("+-*/", ch)) {
            if(token == Separator) {
                 token = Operator;
                 op = ch;
            } else EXIT();
        } else if(isdigit(ch) || ch =='.') {
            if(token == Separator) {
                token = Operand;
                begin = expr;
            } else if(token == Operator) {
                if(expr[-1]=='-') {
                    token = Operand;
                    begin = expr-1;
                    op = 0;
                } else EXIT();
            }
        }
        expr++;
    }
    EXIT();
}