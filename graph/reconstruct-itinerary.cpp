class Solution {
public:
    unordered_map<string,set<string> > m;
    vector<string> res;
    void dfs(string s){
        while(!m[s].empty()){
            auto it = m[s].begin();
            string str = *it;
            m[s].erase(it);
            dfs(str);
        }
        res.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
        int n = t.size();
        for(int i=0;i<n;i++) m[t[i][0]].insert(t[i][1]);
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};
