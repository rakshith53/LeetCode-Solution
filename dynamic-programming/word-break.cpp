class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<bool> dp(n,false);
        string tmp;
        for(int j=0;j<n;j++){
            tmp = "";
            for(int i=j;i>=0;i--){
                tmp = s[i] + tmp;
                if(i>0 && m.find(tmp)!=m.end() && dp[i-1]){
                    dp[j] = true;
                    break;
                }
                else if(i==0 && m.find(tmp)!=m.end()){
                    dp[j] = true;
                }
            }
        }
        return dp[n-1];
    }
};
