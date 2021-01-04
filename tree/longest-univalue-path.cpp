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
    int ans = 0;
    int help(TreeNode* root){
        int l_ = root->left ? help(root->left) : 0;
        int r_ = root->right ? help(root->right) : 0;
        int resl = root->left && root->left->val == root->val ? l_+1 : 0;
        int resr = root->right && root->right->val == root->val ? r_+1 : 0;
        ans = max(ans,resl+resr);
        return max(resl,resr);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        help(root);
        return ans;
    }
};
