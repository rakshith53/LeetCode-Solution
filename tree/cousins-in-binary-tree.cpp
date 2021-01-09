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
    map<int,pair<TreeNode*,int> > m;
    void help(TreeNode* root,TreeNode* p,int x,int y,int l)
    {
        if(!root) return;
        if(root->val==x) m[x] = {p,l};
        if(root->val==y) m[y] = {p,l};
        help(root->left,root,x,y,l+1);
        help(root->right,root,x,y,l+1);
    }
    bool isCousins(TreeNode* root, int x, int y) { 
        m[x] = {NULL,0};
        m[y] = {NULL,0};
        help(root,NULL,x,y,0);
        if((m[x].first!=m[y].first) && (m[x].second==m[y].second))
            return 1;
        return 0;
    }
};
