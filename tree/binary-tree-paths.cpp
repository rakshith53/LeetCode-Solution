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
    vector<string> res;
    void help(TreeNode* root,string cur){
        if(!root) return;
        cur += "->"+to_string(root->val);
        if(!root->left && !root->right) {
            res.push_back(cur.substr(2));
            return;
        }
        help(root->left,cur);
        help(root->right,cur);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans = "";
        help(root,ans);
        return res;
    }
};
