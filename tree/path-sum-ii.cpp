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
    vector<vector<int> > res;
    void help(TreeNode* root,vector<int>& ans,int sum){
        if(!root) return;
        if(!root->left && !root->right && sum==root->val){
            ans.push_back(root->val);
            res.push_back(ans);
            ans.pop_back();
            return ;
        }
        ans.push_back(root->val);
        help(root->left,ans,sum-root->val);
        help(root->right,ans,sum-root->val);
        ans.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if(!root) return res;
        vector<int> ans;
        help(root,ans,sum);
        return res;
    }
};
