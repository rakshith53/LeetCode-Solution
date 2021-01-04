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
    int sum;
    int help(TreeNode* root)
    {
        if(!root) return 0;
        int l_ = help(root->left);
        int r_ = help(root->right);
        sum += abs(l_)+abs(r_);
        return root->val+l_+r_-1;
    }
    int distributeCoins(TreeNode* root) {
        sum=0;
        help(root);
        return sum;
    }
};
