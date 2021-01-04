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
    int sum,l,r;
    void help(TreeNode* root)
    {
        if(!root) return;
        if(root->val>=l && root->val<=r) sum+=root->val;
        if(root->val>=l)help(root->left);
        // free(root->left);
        if(root->val<=r)help(root->right);
        // free(root->right);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum=0;
        l=L;
        r=R;
        help(root);
        root->left=root->right=NULL;
        return sum;
    }
};
