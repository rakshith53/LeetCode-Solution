class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(),l,r,cnt=0;
        for(int i=0;i<(2*n)-1;i++)
        {
            l = i/2;
            r = l+i%2;
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
};
