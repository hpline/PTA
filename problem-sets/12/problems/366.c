#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist()
{
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *node;
    int n;
    while(1) {
        scanf("%d", &n);
        if(n == -1) {
            break;
        }
        node = malloc(sizeof(struct ListNode));
        node->data = n;
        node->next = NULL;
        if(head == NULL) {
            head = node;
        }
        if(tail == NULL) {
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}
struct ListNode *deletem( struct ListNode *L, int m )
{
    struct ListNode *pre = L;
    struct ListNode *delete;
    if(L == NULL) {
        return L;
    }
    while(pre->next) {
        if(pre->next->data == m) {
            delete = pre->next;
            pre->next = pre->next->next;
            free(delete);
        } else {
            pre = pre->next;
        }
    }
    if(L->data == m) {
        delete = L;
        L = L->next;
        free(delete);
    }
    return L;
}