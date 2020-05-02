/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    int first[10000] = {0};
    int index = 0;

    struct ListNode *p = head;
    if(head == NULL || p->next == NULL){
        return head;
    }

    while(p){
        if(index % 2 == 0 && p->next){
            first[index+1] = p->val;
        } else if(index % 2 == 0 && p->next == NULL){
            first[index] = p->val;
        } else {
            first[index-1] = p->val;
        }
        index++;
        p = p->next;
    }

    struct ListNode *front = malloc(sizeof(struct ListNode));
    front->next = NULL;
    struct ListNode *tail = front;
    for(int i=0; i<index; i++){
        struct ListNode *q = malloc(sizeof(struct ListNode));
        q->val = first[i];
        q->next = NULL;
        tail->next = q;
        tail = tail->next;
    }

    return front->next;
}