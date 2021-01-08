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
    ListNode* reverseList(ListNode* head) {
        // ListNode *p,*c,*n;
        // p = NULL;
        // c = head;
        // n = NULL;
        // while(c){
        //     n = c->next;
        //     c->next = p;
        //     p = c;
        //     c = n;
        // }
        // return p;
        ListNode* d = new ListNode(-1);
        d->next = head;
        ListNode *prev = d,*tmp;
        while(head && head->next){
            tmp = prev->next;
            prev->next = head->next;
            head->next = head->next->next;
            prev->next->next = tmp;
        }
        return d->next;
    }
};
