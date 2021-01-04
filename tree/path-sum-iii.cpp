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
    int res = 0;
    void dfs(TreeNode* root,int csum,int sum){
        if(!root) return;
        csum+=root->val;
        if(m.find(csum-sum)!=m.end()){
            res += m[csum-sum];
        }
        m[csum]++;
        dfs(root->left,csum,sum);
        dfs(root->right,csum,sum);
        m[csum]--;
    }
    int pathSum(TreeNode* root, int sum) {
        m[0] = 1;
        dfs(root,0,sum);
        return res;
    }
};
