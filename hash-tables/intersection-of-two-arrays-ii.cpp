class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n = a.size(),m = b.size(), i=0, j=0;
        vector<int> res;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
                i++;
            else if(a[i]>b[j])
                j++;
            else if(a[i]==b[j])
            {
                res.push_back(a[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
