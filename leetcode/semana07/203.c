#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);        
    }

    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode *p = head->next;
    struct ListNode *ant = head;
    struct ListNode *liberado;

    while ( p != NULL ) {
        if ( p->val == val) {
            liberado = p;
            ant->next = p->next;
            p = p->next;
            free(liberado);
        } else {
            ant = p;
            p = p->next;
        }
    }

    return head;

    
}