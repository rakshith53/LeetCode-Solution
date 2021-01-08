class Solution {
public:
    struct TrieNode {
        string word;
        TrieNode* children[26];
        TrieNode(){
            string word = "";
            memset(children,NULL,sizeof(children));
        }
    };
    
    TrieNode* root = new TrieNode();
    
    void buildTrie(vector<string>& dict){
        TrieNode* cur;
        int val;
        bool f = true;
        for(string s:dict){
            cur = root;
            f = true;
            for(char c:s){
                val = c-'a';
                if(!cur->children[val]) cur->children[val] = new TrieNode();
                cur = cur->children[val];
                if(cur->word!="") {f=false;break;}
            }
            if(f) cur->word = s;
        }
    }
    
    string dfs(string& s,TrieNode* cur){
        int n = s.size(),val;
        for(int i=0;i<n;i++){
            val = s[i] - 'a';
            if(!cur->children[val]) return s;
            cur = cur->children[val];
            if(cur->word!="") return cur->word;
        }
        return s;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        buildTrie(dict);
        vector<string> sent;
        string tmp;
        stringstream s(sentence);
        while(getline(s,tmp,' ')){
            sent.push_back(tmp);
        }
        TrieNode* cur;
        for(string& s:sent){
            cur = root;
            s = dfs(s,cur);
        }
        string res = "";
        for(string s:sent) res += (s + " ");
        res.pop_back();
        return res;
    }
};
