class Solution {
public:
    int arrayPairSum(vector<int>& a) {
        sort(a.begin(),a.end());
        int res = 0;
        int n = a.size();
        for(int i=0;i<n;i+=2)
            res += a[i];
        return res;
    }
};
