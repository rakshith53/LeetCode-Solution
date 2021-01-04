class Solution {
public:
    string convert(string s, int k) {
        if(k==1) return s;
        vector<string> v(k);
        bool f = false;
        int n = s.size(),a = 0;
        for(int i=0;i<n;i++)
        {
            v[a] += s[i];
            if(a==0 || a==k-1) f=!f;
            a += (f==false ? -1 : 1);
        }
        string res;
        for(int i=0;i<k;i++)
            res+=v[i];
        return res;
    }
};
