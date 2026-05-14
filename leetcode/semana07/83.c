#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if ( head == NULL) {
        return NULL;
    }
    
    struct ListNode *p = head;
    struct ListNode *prox = head->next;
    struct ListNode *liberado;

    while ( prox != NULL ) {
        if ( p->val == prox->val) {
            liberado = prox;
            prox = prox->next;
            p->next = prox;
            free(liberado);
        } else {
            p = prox;
            prox = prox->next;
        }
    }

    return head;
}