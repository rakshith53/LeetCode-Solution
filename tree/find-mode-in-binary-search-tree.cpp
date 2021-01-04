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
    int cur=0,ans=0,pre=INT_MIN;
    vector<int> res;
    void in(TreeNode* root){
        if(!root) return;
        in(root->left);
        if(pre==root->val) cur++;
        else cur = 1;
        if(cur > ans){
            ans = cur;
            res.clear();
            res.push_back(root->val);
        }
        else if(cur == ans)
            res.push_back(root->val);
        pre = root->val;
        in(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        in(root);
        return res;
    }
};
