class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n = nums.size(),right = -1,left,sum=0,cnt = 0;
        m[0] = -1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(m.find(sum-target)!=m.end()){
                left = m[sum-target];
                if(left>=right){
                    cnt++;
                    right = i;
                }
            }
            m[sum] = i;
        }
        return cnt;
    }
};
