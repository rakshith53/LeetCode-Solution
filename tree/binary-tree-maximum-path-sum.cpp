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
    int ans = INT_MIN;
    int help(TreeNode* root){
        if(!root) return 0;
        int l_ = max(0,help(root->left));
        int r_ = max(0,help(root->right));
        ans = max(ans,(l_+r_+root->val));
        return max(l_,r_)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        help(root);
        return ans;
    }
};
