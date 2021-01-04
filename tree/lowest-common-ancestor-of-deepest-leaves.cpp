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
    TreeNode* ans;
    int maxH;
    int help(TreeNode* root,int h)
    {
        if(!root) return h-1;
        int l = help(root->left,h+1);
        int r = help(root->right,h+1);
        maxH = max(maxH,h);
        if(l==maxH && r==maxH)
            ans = root;
        return (l>r ? l : r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        help(root,0);
        return ans;
    }
};
