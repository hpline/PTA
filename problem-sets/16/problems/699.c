#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    PtrToNode cur = NULL;
    PtrToNode head = malloc(sizeof(*head));
    int X;
    scanf("%d", &X);
    head->Next = NULL;
    for(int i = 0; i < X; i++) {
        PtrToNode node = malloc(sizeof(*node));
        int temp;
        scanf("%d", &temp);
        node->Element = temp;
        node->Next = NULL;
        if(head->Next == NULL) {
            cur = node;
            head->Next = node;
        } else {
            cur->Next = node;
            cur = node;
        }
    }
    return head;
}
void Print( List L )
{
    L = L->Next;
    while(L) {
        printf("%d ", L->Element);
        L = L->Next;
    }
    printf("\n");
}

/* Your function will be put here */
List Reverse(List L)
{
	List next = NULL, current = L->Next;
	while (current) {
        List temp = current->Next;
		current->Next = next;
        next = current;
		current = temp;
	}
	L->Next = next;
	return L;
}