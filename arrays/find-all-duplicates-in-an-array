class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n = a.size(),val;
        vector<int>res;
        for(int i=0;i<n;i++){
            val = abs(a[i])-1;
            if(a[val]<0){
                res.push_back(val+1);
                continue;
            }
            a[val] *= -1;
        }
        return res;
    }
};
