class MagicDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        bool word;
        TrieNode* child[26];
        TrieNode(){
            word = false;
            memset(child,NULL,sizeof(child));
        }
    };
    MagicDictionary() {
        
    }
    
    TrieNode* root = new TrieNode();
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        TrieNode* cur;
        int val;
        for(string s:dict){
            cur = root;
            for(char c:s){
                val = c - 'a';
                if(!cur->child[val]) cur->child[val] = new TrieNode();
                cur = cur->child[val];
            }
            cur->word = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool dfs(TrieNode* cur,string s,int cnt){
        if(cnt>1) return false;
        if(!s.compare("")) return cnt==1 && cur->word;
        for(int j=0;j<26;j++){
            if(cur->child[i]){
                if(s[0]==(char)i+'a'){
                    if(dfs(cur->child[i],s.substr(1),cnt))
                        return true;
                }
                else{
                    if(dfs(cur->child[i],s.substr(1),cnt+1))
                        return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
