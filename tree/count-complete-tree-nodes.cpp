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
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    public: 
        int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        TreeNode *lef = root, *righ = root;
        int height = 0;
        while (righ != NULL) {
            lef = lef->left;
            righ = righ->right;
            height++;
        }
        if (lef == NULL)
            return (1 << height) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
