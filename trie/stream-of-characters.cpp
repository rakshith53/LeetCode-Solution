class StreamChecker {
public:
    struct TrieNode{
        bool word;
        vector<TrieNode*> child;
        TrieNode(){
            word = false;
            child.resize(26,NULL);
        }
    };
    TrieNode* root = new TrieNode();
    int len = 0;
    string str = "";
    void build(vector<string>& words){
        int val;
        TrieNode* cur = root;
        for(string s:words){
            if(s.size() > len)
                len = s.size();
            reverse(s.begin(),s.end());
            cur = root;
            for(char c:s){
                val = c - 'a';
                if(!cur->child[val]) cur->child[val] = new TrieNode();
                cur = cur->child[val];
            }
            cur->word = true;
        }
    }
    StreamChecker(vector<string>& words) {
        build(words);
    }
    
    bool query(char l) {
        str = l + str;
        if(str.size() > len)
            str.pop_back();
        // cout<<str;
        TrieNode* cur = root;
        int k = len;
        if(str.size() < len)
            k = str.size();
        for(int i=0;i<k && cur;i++){
            if(cur->word) return true;
            else if(!cur->child[str[i]-'a']) return false;
            cur = cur->child[str[i]-'a'];
        }
        return cur->word;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
