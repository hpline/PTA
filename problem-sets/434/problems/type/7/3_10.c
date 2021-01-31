#include <stdio.h>
#include <stdlib.h>
#define Swap(x,y) {int tmp=x;x=y;y=tmp;}

typedef struct PillarT {
    int *p;
    int  top;
    char ch;
} *Pillar;

Pillar Create(char ch, int n)
{
    Pillar p = malloc(sizeof(*p));
    p->p = malloc(sizeof(int)*n);
    p->ch = ch;
    p->top = 0;
    return p;
}

int IsEmpty(Pillar p)
{
    return p->top == 0;
}

int BiggerThan(Pillar x, Pillar y)
{
    return x->p[x->top-1] > y->p[y->top-1];
}

Pillar pillar[3];

void move(int small, int large)
{
    if(IsEmpty(pillar[small]) && IsEmpty(pillar[large])) {
        return ;
    } else if( IsEmpty(pillar[small])) {
        Swap(small, large);
    } else if(!IsEmpty(pillar[large]) && BiggerThan(pillar[small], pillar[large])) {
        Swap(small, large);
    }
    pillar[large]->p[pillar[large]->top++] = pillar[small]->p[--(pillar[small]->top)];
    printf("%c -> %c\n", pillar[small]->ch, pillar[large]->ch);
}

int main()
{
    Pillar c;
    int n;
    scanf("%d", &n);
    pillar[0] = Create('a', n);
    pillar[1] = Create('b', n);
    pillar[2] = c = Create('c', n);
    for (int i = n; i >= 1; i--) pillar[0]->p[pillar[0]->top++] = i;
    if(n % 2 == 1) {
        Pillar tmp = pillar[1];
        pillar[1] = pillar[2];
        pillar[2] = tmp;
    }
    int pos = 0;
    while(c->top < n) {
        int pos1 = (pos+1)%3;
        int pos2 = (pos1+1)%3;
        int pos3 = (pos2+1)%3;
        move(pos, pos1);
        move(pos2, pos3);
        pos = pos1;
    }
}