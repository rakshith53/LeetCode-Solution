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
    void dfs(TreeNode* r, int x, int y, map<int, map<int, set<int>>> &m) {
        if (r != nullptr) {
            m[x][y].insert(r->val);
            dfs(r->left, x - 1, y + 1, m);
            dfs(r->right, x + 1, y + 1, m);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* r) {
        map<int, map<int, set<int>>> m;
        dfs(r, 0, 0, m);
        vector<vector<int> > res;
        
        for (auto itx = m.begin(); itx != m.end(); ++itx) {
            vector<int> tmp;
                for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
                    for(auto k=ity->second.begin();k!=ity->second.end();++k)
                        tmp.push_back(*k);
                }
            res.push_back(tmp);
        }
        return res;
    }
};
