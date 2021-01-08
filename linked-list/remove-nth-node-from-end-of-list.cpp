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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* d = new ListNode(-1);
        d->next = head;
        ListNode* cur = d;
        ListNode* slow = d;
        k++;
        while(k-- && cur){
            cur = cur->next;
        }
        while(cur){
            cur = cur->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return d->next;
    }
};
