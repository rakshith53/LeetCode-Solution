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
    int get(vector<int>& inorder,int s,int e,int val){
        for(int i=s;i<=e;i++){
            if(inorder[i]==val)
                return i;
        }
        return -1;
    }
    TreeNode* help(vector<int>& inorder,vector<int>& postorder,int s,int e,int& ind){
        if(s>e) return NULL;
        TreeNode* root = new TreeNode(postorder[ind--]);
        if(s==e) return root;
        int k = get(inorder,s,e,root->val);
        root->right = help(inorder,postorder,k+1,e,ind);
        root->left = help(inorder,postorder,s,k-1,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int ind = n-1;
        return help(inorder,postorder,0,n-1,ind);
    }
};
