class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {
        unordered_map<int,int> m;
        m[0] = 1;
        int n = a.size(),csum=0,ans=0;
        for(int i=0;i<n;i++){
            csum += a[i];
            if(m.find(csum-k)!=m.end())
                ans += m[csum-k];
            m[csum]++;
        }
        return ans;
    }
};
