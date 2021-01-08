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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* d = new ListNode(-1);
        d->next = head;
        ListNode* prev = d;
        
        for(int i=0;i<m-1;i++)
            prev = prev->next;
        
        ListNode *cur = prev->next,*tmp;
        for(int i=0;i<n-m;i++){
            tmp = prev->next;
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = tmp;
        }
        return d->next;
    }
};
