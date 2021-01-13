class Trie {
public:
    struct TrieNode{
        bool word;
        TrieNode* child[26];
        TrieNode(){
            memset(child,NULL,sizeof(child));
            word = false;
        }
    };
    /** Initialize your data structure here. */
    Trie() {
        
    }
    TrieNode* root = new TrieNode();
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        int val,n = word.size();
        for(int i=0;i<n;i++){
            val = word[i] - 'a';
            if(!cur->child[val]) cur->child[val] = new TrieNode();
            cur = cur->child[val];
        }
        cur->word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        int val,n = word.size();
        for(int i=0;i<n;i++){
            val = word[i] - 'a';
            if(!cur->child[val]) return false;
            cur = cur->child[val];
        }
        return cur->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* cur = root;
        int val,n = word.size();
        for(int i=0;i<n;i++){
            val = word[i] - 'a';
            if(!cur->child[val]) return false;
            cur = cur->child[val];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
