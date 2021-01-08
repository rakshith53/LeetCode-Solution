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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* d = new ListNode(-1);
        ListNode* prev = d;
        while(head){
            while(head->next && head->val==head->next->val)
                head = head->next;
            prev->next = head;
            head = head->next;
            prev = prev->next;
        }
        return d->next;
    }
};
