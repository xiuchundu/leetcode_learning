/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* start, * fast, *p;
    p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->val=0;
    p->next=head;//为了对付特殊情况，所以创建一个新的节点，该节点位于head之前

    fast = p;
    start = p;
    
    while(n != 0){
        fast = fast->next;
        n--;
    }

    while(fast->next != NULL){
        fast = fast->next;
        start = start->next;
    }
    
    start->next=start->next->next;

    return p->next;
}