/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* cur = head;
        while(cur){
            Node* t = new Node(cur->val);
            t->next = cur->next;
            cur->next = t;
            cur = cur->next->next;
        }
        cur = head;
        while(cur){
            if(cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node* copyh = head->next;
        Node* copy = copyh;
        cur = head;
        while(copy && cur){
            cur->next = cur->next ? cur->next->next : cur->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            cur = cur->next;
            copy = copy->next;
        }
        return copyh;
    }
};
