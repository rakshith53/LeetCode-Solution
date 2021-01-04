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
    TreeNode* getTargetCopy(TreeNode* r1, TreeNode* r2, TreeNode* target) {
        if(!r1)  return r1;
        if(r1==target) return r2;
        TreeNode* res = NULL;
        res = getTargetCopy(r1->left,r2->left,target);
        if(!res) res = getTargetCopy(r1->right,r2->right,target);
        return res;
    }
};
