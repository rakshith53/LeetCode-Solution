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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> q;
        int i=0;
        q.push_back(root);
        while(i<q.size() && q[i]){
            q.push_back(q[i]->left);
            q.push_back(q[i]->right);
            i++;
        }
        while(i<q.size() && !q[i]) i++;
        return i==q.size();
    }
};
