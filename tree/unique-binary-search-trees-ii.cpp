class Solution {
public:
    vector<TreeNode*> help(int start,int end){
        vector<TreeNode*> v;
        if(start>end){
            v.push_back(NULL);
            return v;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = help(start,i-1);
            vector<TreeNode*> right = help(i+1,end);
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return n==0 ? vector<TreeNode*> {} : help(1,n);
    }
};
