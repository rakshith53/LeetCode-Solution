/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *cur)
    {
        int cnt = 0;
        while(cur)
        {
            cur = cur->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        int dif = abs(l1-l2);
        if(l1>l2){
            while(dif--)
                headA = headA->next;
        }
        else{
            while(dif--)
                headB = headB->next;
        }
        while(headA && headB && headA!=headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA==headB ? headA : NULL;
    }
};
