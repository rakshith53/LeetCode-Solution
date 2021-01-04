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
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(!root) return NULL;
        if(root->val == k){
            if(!root->left && !root->right) return NULL;
            if(!root->left || !root->right) return root->left ? root->left : root->right;
            TreeNode *tmp = root->right;
            TreeNode *cur = root->right;
            while(tmp->left) tmp = tmp->left;
            tmp->left = root->left;
            delete(root);
            return cur;
        }
        else if(root->val < k) root->right = deleteNode(root->right,k);
        else root->left = deleteNode(root->left,k);
        return root;
    }
};
