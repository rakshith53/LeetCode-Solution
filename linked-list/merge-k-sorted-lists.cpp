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
    struct comp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& a){
        priority_queue<ListNode*,vector<ListNode*>,comp> q;
        int n = a.size();
        for(int i=0;i<n;i++)
            if(a[i])
                q.push(a[i]);
        ListNode *d = new ListNode(-1);
        ListNode *tmp,*cur = d;
        while(!q.empty()){
            tmp = q.top();
            q.pop();
            cur->next = tmp;
            if(tmp->next) q.push(tmp->next);
            cur = cur->next;
        }
        return d->next;
    }
};
