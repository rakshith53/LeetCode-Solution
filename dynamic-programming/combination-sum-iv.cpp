class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //sort(nums.begin(),nums.end());
        vector<unsigned long int> dp(target+1,0);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(int a:nums){
                if(a > i) break;
                dp[i] += dp[i-a];
            }
        }
        return (int)dp[target];
    }
};
