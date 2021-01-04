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
    int help(TreeNode* root){
        if(!root) return 0;
        int l_ = help(root->left);
        if(l_ == -1) return -1;
        int r_ = help(root->right);
        if(r_ == -1) return -1;
        if(abs(l_-r_)>1) return -1;
        return max(l_,r_)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return help(root) == -1 ? false : true;
    }
};
