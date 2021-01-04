class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int n = s.size(),end = 0,start = 0;
        int ans = INT_MIN,len = 0;
        vector<int> m(256,0);
        while(end<n){
            if(m[s[end]]==1) len++;
            m[s[end]]++;
            end++;
            while(len>0){
                if(m[s[start]]>1) len--;
                m[s[start]]--;
                start++;
            }
            ans = max(ans,end-start);
        }
        return ans;
    }
};
