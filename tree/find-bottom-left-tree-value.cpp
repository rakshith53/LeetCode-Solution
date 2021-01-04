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
    int data,d=-1;
    void help(TreeNode* root,int l)
    {
        if(!root) return;
        if(l>d){
            data = root->val;
            d=l;
        }
        help(root->left,l+1);
        help(root->right,l+1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        //return 1;
        help(root,0);
        return data;
    }
};
