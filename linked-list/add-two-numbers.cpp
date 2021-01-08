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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* d = new ListNode(-1);
        ListNode* cur = d;
        int c = 0,sum;
        while(l1 || l2 || c){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            ListNode* tmp = new ListNode(sum%10);
            c = sum/10;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return d->next;
    }
};
