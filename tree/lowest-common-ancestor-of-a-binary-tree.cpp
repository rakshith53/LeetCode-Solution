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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p || root==q) return root;
        TreeNode* l_ = lowestCommonAncestor(root->left,p,q);
        TreeNode* r_ = lowestCommonAncestor(root->right,p,q);
        if(l_ && r_) return root;
        return l_ ? l_ : r_;
    }
};
