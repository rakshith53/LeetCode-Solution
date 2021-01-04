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
    void help(TreeNode* root,bool f){
        if(!root) return;
        if(!f && !root->left && !root->right){
            sum+=root->val;
            return;
        }
        help(root->left,false);
        help(root->right,true);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        help(root,false);
        return sum;
    }
};
