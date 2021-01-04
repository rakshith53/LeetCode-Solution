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
class CBTInserter {
public:
    queue<TreeNode*> q;
    TreeNode* cur;
    TreeNode* head;
    CBTInserter(TreeNode* root) {
        head = root;
        q.push(root);
        while(true){
            cur = q.front();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            if(cur->left && cur->right) q.pop();
            else break;
        }
    }
    
    int insert(int v) {
        cur = q.front();
        TreeNode* tmp = new TreeNode(v);
        if(cur->left == NULL) {
            cur->left = tmp;
            q.push(tmp);
        }
        else {
            cur->right = tmp;
            q.push(tmp);
        }
        if(cur->left && cur->right) q.pop();
        return cur->val;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
