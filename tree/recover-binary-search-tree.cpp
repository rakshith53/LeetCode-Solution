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
    TreeNode *prev = NULL,*first = NULL,*last = NULL;
    int val = INT_MIN;
    void help(TreeNode* root){
        if(!root) return;
        help(root->left);
        if(first==NULL && val>root->val) first = prev;
        if(first!=NULL && val>root->val) last = root;
        prev = root;
        val = root->val;
        help(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        help(root);
        swap(first->val,last->val);
    }
};
