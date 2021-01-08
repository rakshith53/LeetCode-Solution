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
    ListNode* reverse(ListNode* head){
        ListNode* p = NULL;
        ListNode* cur = head;
        ListNode* n = NULL;
        
        while(cur){
            n = cur->next;
            cur->next = p;
            p = cur;
            cur = n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(fast){
            slow = slow->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
        while(head && slow){
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
