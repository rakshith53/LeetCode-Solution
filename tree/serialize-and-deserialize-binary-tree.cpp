/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    int get(string& s){
        int p = s.find(',');
        int val = stoi(s.substr(0,p));
        s = s.substr(p+1);
        return val;
    }
    TreeNode* help(string& s){
        if(s[0]=='#'){
            if(s.size()>1) s = s.substr(2);
            return NULL;
        }
        TreeNode* root = new TreeNode(get(s));
        root->left = help(s);
        root->right = help(s);
        return root;
    }
    TreeNode* deserialize(string data) {
        return help(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
