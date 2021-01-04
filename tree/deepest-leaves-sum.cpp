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
    int val = INT_MIN,h=-1,ans=0;
    void dfs(TreeNode* root,int l){
        if(!root) return;
        if(h<l){
            ans = root->val;
            h = l;
        }
        else if(h==l) ans += root->val;
        dfs(root->left,l+1);
        dfs(root->right,l+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        dfs(root,0);
        return ans;
    }
};
