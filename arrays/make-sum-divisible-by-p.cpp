class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(int i:nums)
            sum = (sum + i%p)%p;
        int csum = 0,diff,res = INT_MAX;
        unordered_map<int,int> m;
        m[0] = -1;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            csum = (csum + nums[i]%p)%p;
            diff = (csum - sum + p)%p;
            m[csum] = i;
            if(m.find(diff)!=m.end()){
                res = min(res,i-m[diff]);
            }
        }
        return res!=n ? res : -1;
    }
};
