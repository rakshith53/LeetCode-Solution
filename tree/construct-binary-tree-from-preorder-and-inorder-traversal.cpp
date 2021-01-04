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
    int get(vector<int>& inorder,int val,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==val)
                return i;
        }
        return -1;
    }
    TreeNode* help(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int& ind){
        if(ps > pe) return NULL;
        TreeNode* root = new TreeNode(preorder[ind++]);
        if(ps==pe) return root;
        int k = get(inorder,root->val,ps,pe);
        root->left = help(preorder,inorder,ps,k-1,ind);
        root->right = help(preorder,inorder,k+1,pe,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ps = 0,pe = preorder.size()-1,ind = 0;
        return (help(preorder,inorder,ps,pe,ind));
    }
};
