/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *p;
    int cont=0;
    int meio

    p = head;
    
    while(p != NULL){
        p = p->next;
        cont ++;
    }

    p = head;

    meio = cont/2;

    for(int i=0; i < meio; i++){
        p = p->next;
    }

    return p;
    
}