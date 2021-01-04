class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        map<int,int> m;
        m[0] = 1;
        int res=0,sum=0,n=a.size();
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            if(m.find(sum-k)!=m.end())
            {
                res += m[sum-k];
            }
            m[sum]++;
        }
        return res;
    }
};
