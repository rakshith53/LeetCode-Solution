/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void help(TreeNode* root,int d)
    {
        if(!root) return;
        if(ans.size()<d) ans.push_back(root->val);
        help(root->right,d+1);
        help(root->left,d+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ans;
        help(root,1);
        return ans;
    }
};
