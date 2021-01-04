class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==0) return {};
        int cnt1=0,cnt2=0,num1=INT_MAX,num2=INT_MAX;
        int n = nums.size();
        for(int a: nums){
            if(a==num1){
                cnt1++;
            }
            else if(a==num2){
                cnt2++;
            }
            else if(cnt1==0){
                num1 = a;
                cnt1++;
            }
            else if(cnt2==0){
                num2 = a;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=cnt2=0;
        for(int a:nums){
            if(num1==a)
                cnt1++;
            else if(num2==a)
                cnt2++;
        }
        vector<int> res;
        if(cnt1>n/3) res.push_back(num1);
        if(cnt2>n/3) res.push_back(num2);
        return res;
    }
};
