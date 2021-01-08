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
    int get(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = get(head);
        ListNode* d = new ListNode(-1);
        ListNode *prev = d,*cur = head,*tmp;
        d->next = head;
        for(int i=0;i<len/k;i++){
            for(int j=1;j<k;j++){
                tmp = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = tmp;
            }
            prev = cur;
            cur = cur->next;
        }
        return d->next;
    }
};
