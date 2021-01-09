class Solution {
public:
    vector<vector<string> > res;
    int n;
    bool isValid(int l,int r,string s){
        while(l<=r) {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(string& s,int ind,vector<string>& ans){
        if(ind==n){
            res.push_back(ans);
            return;
        }
        for(int i=ind;i<n;i++){
            if(isValid(ind,i,s)){
                ans.push_back(s.substr(ind,i-ind+1));
                dfs(s,i+1,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.size()==0) return res;
        n = s.size();
        vector<string> ans;
        dfs(s,0,ans);
        return res;
    }
};
