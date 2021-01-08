class CombinationIterator {
public:
    vector<string> res;
    int n,z=0,x;
    void dfs(string s,int k,int ind,string cur){
        if(k==0) res.push_back(cur);
        if(ind==n) return;
        for(int i=ind;i<n;i++){
            cur.push_back(s[i]);
            dfs(s,k-1,i+1,cur);
            cur.pop_back();
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        n = characters.size();
        string cur = "";
        dfs(characters,combinationLength,0,cur);
        x = res.size();
    }
    
    string next() {
        return res[z++];
    }
    
    bool hasNext() {
        return z<x;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
