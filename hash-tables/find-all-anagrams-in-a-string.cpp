class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> mp(26,0);
        for(char c:p) mp[c-'a']++;
        int end=0,start=0,len=p.size(),z=p.size();
        vector<int> res;
        while(end<n){
            if(mp[s[end]-'a']>0){
                len--;
            }
            mp[s[end]-'a']--;
            end++;
            while(len==0){
                if(end-start==z)
                    res.push_back(start);
                if(mp[s[start]-'a']==0)
                    len++;
                mp[s[start]-'a']++;
                start++;
            }
        }
        return res;
    }
};
