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
class FindElements {
public:
    unordered_map<int,bool> m;
    void fill(TreeNode* root,int val){
        if(!root) return;
        root->val = val;
        m[root->val] = true;
        if(root->left) fill(root->left,(val*2)+1);
        if(root->right) fill(root->right,(val*2)+2);
    }
    FindElements(TreeNode* root) {
        fill(root,0);
    }
    
    bool find(int target) {
        return m.find(target)!=m.end() ? true : false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
