class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        bool word;
        vector<TrieNode*> next;
        TrieNode(){
            word = false;
            next.resize(26,NULL);
        }
    };
    TrieNode* root = new TrieNode();
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        int val;
        for(char c:word){
            val = c-'a';
            if(!cur->next[val]) cur->next[val] = new TrieNode();
            cur = cur->next[val];
        }
        cur->word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool dfs(string word,int ind,TrieNode* cur){
        for(int i=ind;i<word.size();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(cur->next[j] && dfs(word,i+1,cur->next[j]))
                        return true;
                }
                return false;
            }
            if(!cur->next[word[i]-'a']) return false;
            cur = cur->next[word[i]-'a'];
        }
        return cur->word;
    }
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
