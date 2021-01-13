class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(10001,0);
        for(int a: nums) dp[a]+=a;
        int prev = 0,cur = 0,temp;
        for(int i=0;i<10001;i++){
            temp = max(prev+dp[i],cur);
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};
        
