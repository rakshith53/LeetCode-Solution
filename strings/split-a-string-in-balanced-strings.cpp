class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0,r = 0,ans = 0,n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='L')
                l++;
            if(s[i]=='R')
                r++;
            if(l==r){
                ans++;
                l=0;
                r=0;
            }
        }
        return ans;
    }
};
