/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* d = new ListNode(-1);
        d->next = head;
        ListNode* p = d;
        ListNode* cur = head;
        while(p->next && cur->next){
            p->next = cur->next;
            cur->next = cur->next->next;
            p->next->next = cur;
            p = cur;
            cur = p->next;
        }
        return d->next;
    }
};
