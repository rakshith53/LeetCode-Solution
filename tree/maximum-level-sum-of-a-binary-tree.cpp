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
    unordered_map<int,int> m;
    void dfs(TreeNode* root,int l){
        if(!root) return;
        m[l]+=root->val;
        if(root->left)dfs(root->left,l+1);
        if(root->right)dfs(root->right,l+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int ans = INT_MIN,val;
        for(auto it=m.begin();it!=m.end();it++){
            if(ans < it->second){
                ans = it->second;
                val = it->first;
            }
        }
        return val;
    }
};
