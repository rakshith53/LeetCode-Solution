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
    string smallestFromLeaf(TreeNode* root,string cur = "") {
        if(!root) return "~";
        cur = (char)(root->val+'a') + cur;
        string l_ = smallestFromLeaf(root->left,cur);
        string r_ = smallestFromLeaf(root->right,cur);
        return (l_==r_ && l_=="~") ? cur :  min(l_,r_);
    }
};
