class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        int n = nums.size(),sum=0,cnt=0;
        m[0] = 1;
        for(int a: nums){
            sum = (sum + a%k + k)%k;
            cnt += m[sum]++;
        }
        return cnt;
    }
};
