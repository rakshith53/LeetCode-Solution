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
    vector<TreeNode*> res;
    TreeNode* help(TreeNode* root){
        if(!root) return NULL;
        root->left = help(root->left);
        root->right = help(root->right);
        if(m.find(root->val)!=m.end()){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return res;
        for(int a:to_delete) m[a]++;
        root = help(root);
        if(root) res.push_back(root);
        return res;
    }
};
