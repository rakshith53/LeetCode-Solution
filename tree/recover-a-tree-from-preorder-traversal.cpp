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
    TreeNode* recoverFromPreorder(string s) {
        vector<TreeNode*> st;
        int n = s.size();
        for(int i=0,val,d;i<n;){
            for(d=0;s[i]=='-';i++)
                d++;
            for(val=0;i<n && s[i]!='-';i++)
                val = val*10+(s[i]-'0');
            TreeNode* tmp = new TreeNode(val);
            while(d < st.size()) st.pop_back();
            if(!st.empty()){
                if(!st.back()->left) st.back()->left = tmp;
                else st.back()->right = tmp;
            }
            st.push_back(tmp);
        }
        return st[0];
    }
};
