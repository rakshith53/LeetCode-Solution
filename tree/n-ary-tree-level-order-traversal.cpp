/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> >res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        Node* cur;
        int n;
        vector<int> ans;
        while(!q.empty())
        {
            n = q.size();
            ans.clear();
            while(n--)
            {
                cur = q.front();
                q.pop();
                ans.push_back(cur->val);
                for(auto i : cur->children)
                    q.push(i);
            }
            res.push_back(ans);     
        }
        return res;
    }
};
