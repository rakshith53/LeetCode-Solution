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
    bool help(TreeNode* root)
    {
        if(!root) return true;
        bool l_ = help(root->left);
        bool r_ = help(root->right);
        if(!l_) root->left = NULL;
        if(!r_) root->right = NULL;
        if(root->val==0 && !root->left && !root->right) 
            return false;
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        help(root);
        return root;
    }
};
