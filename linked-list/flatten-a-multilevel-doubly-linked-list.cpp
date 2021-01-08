/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node* cur = head;
        Node* tmp;
        while(cur){
            if(cur->child){
                if(cur->next) s.push(cur->next);
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
            }
            else if(!cur->next && !s.empty()){
                cur->next = s.top();
                cur->next->prev = cur;
                s.pop();
            }
            cur = cur->next;
        }
        return head;
    }
};
