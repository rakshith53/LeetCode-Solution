class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,k=1;
        for(int a:nums)
            if(i<k || nums[i-k]<a)
                nums[i++]=a;
        return i;
    }
};
