class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        vector<string> res;
        vector<int> ans(26,INT_MAX);
        for(string s: a){
            vector<int> cnt(26,0);
            for(char c: s) cnt[c-'a']++;
            for(int i=0;i<26;i++) ans[i] = min(ans[i],cnt[i]);
        }
        int k;
        for(int i=0;i<26;i++){
            k = ans[i];
            while(k--) res.push_back(string(1,i+'a'));
        }
        return res;
    }
};
