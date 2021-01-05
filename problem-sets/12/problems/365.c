#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
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
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
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
struct ListNode *getodd( struct ListNode **L )
{
    struct ListNode *p = *L;
    struct ListNode *odd = NULL;
    struct ListNode *odd_tail = NULL;
    struct ListNode *even = NULL;
    struct ListNode *even_tail = NULL;
    while (p) {
        if(p->data % 2 == 1) {
            if(odd == NULL) {
                odd = p;
            }
            if(odd_tail == NULL) {
                odd_tail = p;
            } else {
                odd_tail->next = p;
                odd_tail = p;
            }
        } else {
            if(even == NULL) {
                even = p;
            }
            if(even_tail == NULL) {
                even_tail = p;
            } else {
                even_tail->next = p;
                even_tail = p;
            }   
        }
        p = p->next;
    }
    if(odd_tail != NULL) {
        odd_tail->next = NULL;
    }
    if(even_tail != NULL) {
        even_tail->next = NULL;
    }
    *L = even;
    return odd;
}