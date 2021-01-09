class Solution {
public:
    int n;
    unordered_set<string> map;
    bool match(string& a,string& b){
        if(a.size()!=b.size()) return false;
        int m = a.size(),cnt=0;
        for(int i=0;i<m && cnt<3;i++)
            if(a[i]!=b[i]) cnt++;
        return cnt==2;
    }
    void dfs(string s,vector<string>& a){
        for(int i=0;i<n;i++){
            if(map.find(a[i])==map.end() && match(s,a[i])){
                string tmp = a[i];
                map.insert(a[i]);
                dfs(tmp,a);
            }
        }
    }
    int numSimilarGroups(vector<string>& a) {
        n = a.size();
        int res = 0;
        for(int i=0;i<n;i++){
            if(map.find(a[i])==map.end()){
                string tmp = a[i];
                map.insert(a[i]);
                res++;
                dfs(tmp,a);
            }
        }
        return res;
    }
};
