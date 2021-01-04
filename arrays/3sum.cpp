class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        int l,r,sum,n = a.size();
        vector<vector<int> > res;
        for(int i=0;i<n-2;i++)
        {
            if(a[i]>0) break;
            if(i>0 && a[i]==a[i-1]) continue;
            l = i+1;
            r = n-1;
            sum = 0-a[i];
            while(l<r)
            {
                if(a[l]+a[r]==sum)
                {
                    res.push_back({a[i],a[l],a[r]});
                    while(l<r && a[l]==a[l+1]) l++;
                    while(l<r && a[r]==a[r-1]) r--;
                    l++;
                    r--;
                }
                else if(a[l]+a[r]>sum) r--;
                else l++;
            }
        }
        return res;
    }
};
