/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if(!root) return res;
        deque<TreeNode*> q;
        q.push_back(root);
        int n;
        vector<int> tmp;
        bool f = false;
        TreeNode* cur;
        while(!q.empty()){
            n = q.size();
            tmp.clear();
            while(n--){
                if(f){
                    cur = q.front();
                    q.pop_front();
                    tmp.push_back(cur->val);
                    if(cur->right) q.push_back(cur->right);
                    if(cur->left) q.push_back(cur->left);
                }
                else{
                    cur = q.back();
                    q.pop_back();
                    tmp.push_back(cur->val);
                    if(cur->left) q.push_front(cur->left);
                    if(cur->right) q.push_front(cur->right);
                }
            }
            f = !f;
            res.push_back(tmp);
        }
        return res;
    }
};
