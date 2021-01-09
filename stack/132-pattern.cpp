class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(),max = INT_MIN;
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top() < nums[i]){
                max = s.top();
                s.pop();
            }
            if(nums[i] > max) s.push(nums[i]);
            if(nums[i] < max) return true;
        }
        return false;
    }
};
