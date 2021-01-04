class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        map<string,vector<string> > m;
        int n = a.size();
        string tmp;
        for(int i=0;i<n;i++)
        {
            tmp = a[i];
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(a[i]);
        }
        vector<vector<string> > res;
        int i = 0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
