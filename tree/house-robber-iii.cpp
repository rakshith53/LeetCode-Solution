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
    unordered_map<TreeNode*,int> m;
    int help(TreeNode* root){
        if(!root) return 0;
        if(m.find(root)!=m.end()) return m[root];
        int val = 0;
        if(root->left)
            val += help(root->left->left) + help(root->left->right);
        if(root->right)
            val += help(root->right->left) + help(root->right->right);
        val = max(root->val+val,help(root->left)+help(root->right));
        m[root] = val;
        return m[root];
    }
    int rob(TreeNode* root) {
        return help(root);
    }
};
