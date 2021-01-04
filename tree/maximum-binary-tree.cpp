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
    TreeNode* help(int l,int r,vector<int>& a){
        if(l==r) return  NULL;
        int mid = max_element(a.begin()+l,a.begin()+r)-a.begin(),val = a[mid];
        TreeNode* tmp = new TreeNode(val);
        tmp->left = help(l,mid,a);
        tmp->right = help(mid+1,r,a);
        return tmp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        int l = 0,r = a.size();
        return (help(l,r,a));
    }
};
