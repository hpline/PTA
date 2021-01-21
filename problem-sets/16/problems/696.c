#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            // done = 1;
            break;
        }
    }
    return 0;
}

#include "string.h"
#define MAXN 20
Operation GetOp()
{
    char str[MAXN];
    scanf("%s", str);
    if(!strcmp(str, "Pop")) {
        return pop;
    } else if(!strcmp(str, "Push")) {
        return push;
    } else if(!strcmp(str, "Eject")) {
        return eject;
    } else if(!strcmp(str, "Inject")) {
        return inject;
    }
    return end;
}
void PrintDeque( Deque D )
{
    PtrToNode node = D->Front->Next;
    if(node == NULL) {
        return ;
    }
    printf("Inside Deque:");
    do {
        printf(" %d ", node->Element);
        node = node->Next;
    } while(node != NULL);
    printf("\n");

}

/* Your function will be put here */
Deque CreateDeque()
{
	Deque q = (Deque)malloc(sizeof(struct DequeRecord));
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	p->Last = NULL;		//单独队头没有前节点
	p->Next = NULL;		//单独队头没有后节点
	q->Front = q->Rear = p;		//队头和队尾指向同一节点
	return q;
}
int Push(ElementType X, Deque D)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	if (p == NULL)
		return 0;
	p->Element = X;
	PtrToNode t = D->Front->Next;
	if (t == NULL)		//t为空，即插入第一个节点，队尾需要改变指向
	{
		D->Front->Next = p;
		p->Last = D->Front;
		D->Rear = p;
		return 1;
	}
	else		//t不为空，插入头节点不需要改变队尾指向
	{
		p->Last = D->Front;
		D->Front->Next = p;
		p->Next = t;
		t->Last = p;
		return 1;
	}
}
ElementType Pop(Deque D)
{
	if (D->Front == D->Rear) return ERROR;
	PtrToNode t = D->Front->Next;
	ElementType e = t->Element;
	if (t->Next == NULL)		//t的下一节点为空，即删除队列中的最后一个元素，需要改变队尾指向
	{
		D->Front->Next = NULL;
		D->Front->Last = NULL;
		D->Rear = D->Front;
	}
	else		//t不为空，不需要改变队尾指向
	{
		D->Front->Next = t->Next;
		t->Next->Last = D->Front;
		free(t);
		return e;
	}
}
//尾插和尾出较为简单，不需要判断是否改变队尾和队头指向
int Inject(ElementType X, Deque D)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	if (p == NULL) return 0;
	p->Element = X;
	D->Rear->Next = p;
	p->Last = D->Rear;
	p->Next = NULL;
	D->Rear = p;
	return 1;
}
ElementType Eject(Deque D)
{
	if (D->Front == D->Rear) return ERROR;
	PtrToNode p = D->Rear;
	D->Rear = p->Last;
	p->Last->Next = NULL;
	ElementType e = p->Element;
	free(p);
	return e;
}