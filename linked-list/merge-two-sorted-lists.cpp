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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* d = new ListNode(-1);
        ListNode* cur = d;
        while(a && b){
            if(a->val < b->val){
                d->next = a;
                a = a->next;
            }
            else{
                d->next = b;
                b = b->next;
            }
            d = d->next;
        }
        if(a) d->next = a;
        if(b) d->next = b;
        return cur->next;
    }
};
