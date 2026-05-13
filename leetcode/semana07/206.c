/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *ant = NULL;
    struct ListNode *atual = head;
    struct ListNode *prox = NULL;

    while (atual != NULL) {
        prox = atual->next;

        atual->next = ant;

        ant = atual;
        atual = prox;
    }

    return ant;
}