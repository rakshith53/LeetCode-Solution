class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        vector<int> ans(101,0);
        vector<int> res(a.size(),0);
        int n = a.size();
        for(int i=0;i<n;i++)
            ans[a[i]]++;
        for(int i=1;i<101;i++)
            ans[i] += ans[i-1];
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                res[i]=0;
            else
                res[i] = ans[a[i]-1];
        }
        return res;
    }
};
