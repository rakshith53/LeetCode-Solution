class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        vector<int> res(2,-1);
        int r = a.size()-1,l=0,sum;
        while(l<r){
            sum = a[l]+a[r];
            if(sum==t){
                res[0] = l+1;
                res[1] = r+1;
                return res;
            }
            else if(sum < t) l++;
            else r--;
        }
        return res;
    }
};
