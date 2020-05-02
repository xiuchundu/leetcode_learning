/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *p = head;
    int arr[10000] = {0};
    int index = 0;
    int flag = false;
    while(p){
        arr[index++] = p->val;
        p = p->next;
    }

    if(index % k == 0){
        flag = true;
    }

    if(flag){ //刚好是整数倍
        for(int i=0; i<index; i+=k){
            if(i % k== 0){
                int cur=0;
                for(int j=i; j<=(2*i+k-1)/2; j++){
                    int tmp = arr[j];
                    arr[j] = arr[i+k-1-cur];
                    arr[i+k-1-cur] = tmp;
                    cur++;
                }
            }
        }
    } else { //不是整数倍
        int max = (index / k) * k;
            for(int i=0; i<max; i+=k){
                if(i % k== 0){
                    int cur=0;
                    for(int j=i; j<=(2*i+k-1)/2; j++){
                        int tmp = arr[j];
                        arr[j] = arr[i+k-1-cur];
                        arr[i+k-1-cur] = tmp;
                        cur++;
                    }
                }
            }
    }

    struct ListNode *front = malloc(sizeof(struct ListNode));
    front->next = NULL;
    struct ListNode *tail = front; 

    for(int m=0; m<index; m++){
        struct ListNode *p = malloc(sizeof(struct ListNode));
        p->val = arr[m];
        p->next = NULL;
        tail->next = p;
        tail = tail->next;
    }

    return front->next;
}