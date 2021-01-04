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
    vector<TreeNode*> res;
    unordered_map<string,int>  count;
    string help(TreeNode* root){
        if(!root) return "#";
        string str = to_string(root->val)+","+help(root->left)+","+help(root->right);
        count[str]++;
        if(count[str]==2)
            res.push_back(root);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        help(root);
        return res;
    }
};
