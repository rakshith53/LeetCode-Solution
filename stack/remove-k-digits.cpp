class Solution {
public:
    string removeKdigits(string s, int k) {
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            while(ans.length() && ans.back()>s[i] && k){
                ans.pop_back();
                k--;
            }
            if(!ans.empty() || s[i]!='0')
                ans.push_back(s[i]);
        }
        while(ans.length() &&  k--) ans.pop_back();
        return ans.size()==0 ? "0" : ans;
    }
};
