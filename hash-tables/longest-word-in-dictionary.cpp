class Solution {
public:
    struct TrieNode{
        string word;
        TrieNode* child[26];
        TrieNode(){
            word = "";
            for(int i=0;i<26;i++) child[i] = NULL;
        }
    };
    
    TrieNode* root = new TrieNode();
    string res = "";
    
    void build(vector<string>& word){
        TrieNode* cur;
        int val;
        for(string s:word){
            cur = root;
            for(char c:s) {
                val =  c - 'a';
                if(!cur->child[val]) cur->child[val] = new TrieNode();
                cur = cur->child[val];
            }
            cur->word = s;
        }
    }
    
    string compare(string& a,string& b){
        return a < b ? a : b;
    }
    
    void dfs(TrieNode* root){
        //if(!root) return;
        if(root->word != ""){
            if(root->word.size() > res.size()) res = root->word;
            else if (root->word.size() == res.size()) res = compare(res,root->word);
        }
        for(int i=0;i<26;i++)
            if(root->child[i] && root->child[i]->word!="")
                dfs(root->child[i]);
    }
    
    string longestWord(vector<string>& word) {
        build(word);
        dfs(root);
        return res;
    }
};
