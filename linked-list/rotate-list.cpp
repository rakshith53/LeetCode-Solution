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
    int get(ListNode* cur){
        int len = 0;
        while(cur){
            len++;
            cur = cur->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head) return head;
        ListNode* d = new ListNode(-1);
        d->next = head;
        ListNode* fast = d;
        ListNode* slow = d;
        int len = get(head);
        k = k%len;
        if(k==0) return head;
        k++;
        while(k--)
            fast = fast->next;
        ListNode* prev;
        while(fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        ListNode* rhead = slow->next;
        slow->next = NULL;
        prev->next = head;
        return rhead;
    }
};
