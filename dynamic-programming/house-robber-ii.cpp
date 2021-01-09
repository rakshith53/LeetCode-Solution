class Solution {
public:
    int help(int l,int r,vector<int>& nums){
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return(max(help(0,n-2,nums),help(1,n-1,nums)));
    }
};
