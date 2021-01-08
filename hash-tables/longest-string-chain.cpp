static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int> dp;
        int len,maxl=0;
        string word;
        for(string w: words){
            len = w.size();
            for(int i=0;i<len;i++){
                //word = w.substr(0,i)+w.substr(i+1);
                dp[w] = max(dp[w],dp[w.substr(0,i)+w.substr(i+1)]+1);
            }
           maxl = max(maxl,dp[w]);
        }
        return maxl;
    }
};
