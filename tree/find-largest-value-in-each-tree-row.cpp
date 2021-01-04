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
    vector<int> res;
    void help(TreeNode* root,int h){
        if(!root) return;
        if(h>res.size()) res.push_back(root->val);
        else res[h-1] = max(res[h-1],root->val);
        help(root->left,h+1);
        help(root->right,h+1);
    }
    vector<int> largestValues(TreeNode* root) {
        help(root,1);
        return res;
    }
};
