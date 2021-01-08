class Solution {
public:
    int numJewelsInStones(string a, string s) {
        map<char,int> mp;
        int n = s.size(),m = a.size(),ans = 0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<m;i++){
            ans+=mp[a[i]];
        }
        return ans;
    }
};
