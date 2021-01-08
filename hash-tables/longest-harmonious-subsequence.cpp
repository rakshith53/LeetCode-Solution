class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        int res = 0;
        for(int i:nums){
            m[i]++;
            if(m.find(i-1)!=m.end()){
                res = max(res,m[i]+m[i-1]);
            }
            if(m.find(i+1)!=m.end()){
                res = max(res,m[i]+m[i+1]);
            }
        }
        return res;
    }
};
