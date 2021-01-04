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
    TreeNode* ans = new TreeNode(-1);
    void help(TreeNode* root){
        if(!root) return;
        help(root->left);
        ans->right = root;
        root->left = NULL;
        ans = root;
        help(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return  NULL;
        TreeNode* cur = ans;
        help(root);
        return cur->right;
    }
};
