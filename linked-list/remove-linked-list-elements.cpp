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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur;
        ListNode *prev = NULL;
        while(head && head->val == val) head = head->next;
        cur = head;
        while(cur){
            if(cur->val==val){
                while(cur && cur->val==val)
                    cur = cur->next;
                if(prev) prev->next = cur;
            }
            prev = cur;
            cur = cur ? cur->next : NULL;
        }
        return head;
    }
};
