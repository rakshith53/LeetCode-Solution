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
    int ans = 0;
    int help(TreeNode *root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l_ = help(root->left);
        int r_ = help(root->right);
        ans = max(ans,l_+r_);
        return max(l_,r_)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        help(root);
        return ans;
    }
};
