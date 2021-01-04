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
    int longestZigZag(TreeNode* root) {
    int result = -1;
    int l = rec(root->left,  result, false);
    int r = rec(root->right, result, true );
    return max({ result, l, r }); 
  }
  
  int rec(TreeNode* node, int& result, bool returnLeft) {
    if (!node) return 0;
    int l = rec(node->left,  result, false);
    int r = rec(node->right, result, true );
    result = max({ result, l, r }); 
    return 1 + (returnLeft ? l : r); 
  }
};
