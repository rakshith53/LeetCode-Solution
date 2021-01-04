class Solution {
public:
    bool pre(vector<string>& str,int m)
    {
        string s = str[0].substr(0,m);
        int n = str.size();
        for(int i=1;i<n;i++)
        {
            if(s.compare(str[i].substr(0,m)))
                return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        if(n==0) return "";
        int len = s[0].size(),k;
        for(int i=1;i<n;i++)
        {
            k = s[i].size();
            len = min(len,k);
        }
        int l=0,r=len,mid,ans;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(pre(s,mid)){
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return s[0].substr(0,ans);
    }
};
