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
    int cnt=0;
    void help(TreeNode* root,int val){
        if(!root) return;
        if(root->val>=val){
            cnt++;
            val =  root->val;
        }
        help(root->left,val);
        help(root->right,val);
    }
    int goodNodes(TreeNode* root) {
        help(root,INT_MIN);
        return cnt;
    }
};
