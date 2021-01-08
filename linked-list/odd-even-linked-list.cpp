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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* c1 = head;
        ListNode* c2 = head->next;
        ListNode* tmp = c2;
        while(c2 && c2->next){
            c1->next = c1->next->next;
            c2->next = c2->next->next;
            c1 = c1->next;
            c2 = c2->next;
        }
        c1->next = tmp;
        return head;
    }
};
