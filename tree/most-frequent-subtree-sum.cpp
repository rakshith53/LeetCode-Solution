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
    int cnt = 0;
    int help(TreeNode* root)
    {
        if(!root) return 0;
        int sum =help(root->left)+help(root->right)+root->val;
        cnt = max(cnt,++m[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        help(root);
        vector<int> res;
        for(auto it=m.begin();it!=m.end();it++)
            if(it->second==cnt)
                res.push_back(it->first);
        return res;
    }
};
