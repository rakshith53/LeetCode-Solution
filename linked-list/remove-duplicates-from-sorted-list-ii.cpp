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
        d->next = head;
        ListNode* p = d;
        while(head){
            if(head->next && head->next->val==head->val){
                int val = head->val;
                while(head && head->val==val)
                    head = head->next;
            }
            else{
                p->next = head;
                head = head->next;
                p = p->next;
            }
        }
        p->next = NULL;
        return d->next;
    }
};
