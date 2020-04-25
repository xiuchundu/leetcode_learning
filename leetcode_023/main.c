/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//方法一：递归处理两个链表的合并
struct ListNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2){
    //1，递归结束条件
    if (NULL == l1)
    {
        return l2;
    }
    if (NULL == l2)
    {
        return l1;
    }

    //2，递归条件
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
}

//方法二：有点回溯法的意思
struct ListNode* mergeKListsHandle(struct ListNode** lists, int listsSize){
    int     iCount      = 0;
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    iCount = listsSize;

    if (iCount == 0)
    {
        return NULL;
    }
    else if (iCount == 1)
    {
        return lists[0];
    }
    else if (iCount == 2)
    {
        return mergeTwoList(lists[0], lists[1]);
    }

    l1 = mergeKListsHandle(&lists[0], (iCount + 1) / 2);
    l2 = mergeKListsHandle(&lists[(iCount + 1) / 2], iCount - (iCount + 1) / 2);

    return mergeTwoList(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return mergeKListsHandle(lists, listsSize);
}