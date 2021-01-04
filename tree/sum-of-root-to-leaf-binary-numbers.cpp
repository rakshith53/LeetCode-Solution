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
    int sum = 0;
    void help(TreeNode* root,int ans){
        if(!root) return;
        ans = ans*2 + root->val;
        if(!root->left && !root->right){
            sum+=ans;
            return;
        }
        help(root->left,ans);
        help(root->right,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        help(root,0);
        return sum;
    }
};
