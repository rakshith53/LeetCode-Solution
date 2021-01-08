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
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* prev= NULL, *nex;
        while(cur){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    void reorder(ListNode* l1,ListNode* l2){
        ListNode* tmp;
        while(l2){
            tmp = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = tmp;
        }
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
        //reorder(head,slow);
        ListNode *d = new ListNode(-1);
        
    }
};
