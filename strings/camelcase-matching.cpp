class Solution {
public:
    bool solve(string s,string t) {
        int i=0;
        for(char c: s) {
            if(c==t[i]) i++;
            else if(c>='A' && c<='Z') return false;
        }
        if(i==t.size()) return true;
        else return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string s: queries) {
            ans.push_back(solve(s,pattern));
        }
        return ans;
    }
};
