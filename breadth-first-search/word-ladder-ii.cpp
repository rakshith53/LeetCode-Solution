class Solution {
public:
    vector<vector<string> > res;
    unordered_map<string,vector<string > > g;
    
    void dfs(vector<string>& path,string beginWord,string endWord){
        if(beginWord==endWord)
            res.push_back(path);
        for(string s:g[beginWord]){
            path.push_back(s);
            dfs(path,s,endWord);
            path.pop_back();
        }
    }
    
    bool bfs(string beginWord,string endWord,unordered_set<string>& dict){
        unordered_set<string> cur,next;
        cur.insert(beginWord);
        int n;
        char ch;
        string word;
        while(!cur.empty()){
            if(cur.find(endWord)!=cur.end()) 
                return true;
            for(string s:cur)
                dict.erase(s);
            next.clear();
            for(string s: cur){
                n = s.size();
                word = s;
                for(int i=0;i<n;i++){
                    ch = s[i];
                    for(char c='a';c<='z';c++){
                        if(ch==c) continue;
                        s[i] = c;
                        if(dict.find(s)!=dict.end()){
                            g[word].push_back(s);
                            next.insert(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            swap(next,cur);
        }
        return false;
    }
    
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        vector<string> path = {beginWord};
        if(bfs(beginWord,endWord,dict)){
            dfs(path,beginWord,endWord);
        }
        return res;
    }
};
