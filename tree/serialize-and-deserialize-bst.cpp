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

    // Encodes a tree to a single string.
    void pre(TreeNode* root,string& ans){
        if(!root) return;
        ans += to_string(root->val)+",";
        pre(root->left,ans);
        pre(root->right,ans);
    }
    
    string serialize(TreeNode* root) {
        string ans = "";
        pre(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    int get(string& data,int& pos){
        pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        return val;
    }
    
    TreeNode* de(string& data,int min,int max){
        if(data.size()==0) return NULL;
        int pos=0,val = get(data,pos);
        if(val < min || val > max) return NULL;
        TreeNode* d = new TreeNode(val);
        data = data.substr(pos+1);
        d->left = de(data,min,val);
        d->right = de(data,val,max);
        return d;
    }
    TreeNode* deserialize(string data) {
        if (data=="") return NULL;
        return de(data,INT_MIN,INT_MAX); 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
