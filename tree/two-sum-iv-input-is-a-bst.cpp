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
    unordered_map<int,bool> m;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(m.find(k-root->val)!=m.end()) return true;
        m[root->val] = true;
        return (findTarget(root->left,k) || findTarget(root->right,k));
    }
};
