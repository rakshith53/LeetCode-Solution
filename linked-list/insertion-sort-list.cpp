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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* d = new ListNode(INT_MIN);
        d->next = head;
        ListNode *cur=head,*pre=d;
        while(cur){
            if(cur->next && cur->next->val < cur->val){
                pre = d;
                while(pre->next->val < cur->next->val){
                    pre = pre->next;
                }
                ListNode* tmp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = tmp;
            }
            else cur = cur->next;
        }
        return d->next;
    }
};
