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
    TreeNode* help(int l,int r,vector<int> &a)
    {
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = help(l,mid-1,a);
        root->right = help(mid+1,r,a);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& a) {
        return (help(0,a.size()-1,a));
    }
};
