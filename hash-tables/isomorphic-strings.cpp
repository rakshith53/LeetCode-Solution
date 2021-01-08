class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> ms(256,-1);
        vector<int> mt(256,-1);
        int n = s.size();
        for(int i=0;i<n;i++){
            if(ms[s[i]]!=mt[t[i]]) return false;
            ms[s[i]] = i;
            mt[t[i]] = i;
        }
        return true;
    }
};
