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
    pair<int,TreeNode*> help(TreeNode* root){
        if(!root) return {0,NULL};
        pair<int,TreeNode*> l = help(root->left);
        pair<int,TreeNode*> r = help(root->right);
        return {max(l.first,r.first)+1,l.first==r.first ? root : l.first > r.first ? l.second : r.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return help(root).second;
    }
};
