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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(-1);
        ListNode* after = new ListNode(-1);
        ListNode* cur = head,*bh = before,*ah = after;
        while(cur){
            if(cur->val < x){
                before->next = cur;
                before = before->next;
            }
            else{
                after->next = cur;
                after = after->next;
            }
            cur = cur->next;
        }
        after->next = NULL;
        before->next = ah->next;
        return bh->next;
    }
};
