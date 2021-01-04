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
    unordered_map<int,unsigned>mp;
    unsigned maxwidth=1;
    void dfs(TreeNode*root,int level,unsigned pos)
    {
        if(root==NULL)
            return;
        if(mp.find(level)==mp.end())
            mp[level]=pos;
        else
            maxwidth=max(maxwidth,pos-mp[level]+1);
        dfs(root->left,level+1,2*pos);
        dfs(root->right,level+1,2*pos+1);
    return;
    }

    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root,0,0);
        return maxwidth;
    }
};
