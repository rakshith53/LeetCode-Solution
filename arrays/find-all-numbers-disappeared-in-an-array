class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = a.size(),k;
        for(int i=0;i<n;i++)
        {
            if(a[abs(a[i])-1] > 0)
                a[abs(a[i])-1] = -a[abs(a[i])-1];
        }
        vector<int> res;
        for(int i=0;i<n;i++)
            if(a[i]>0)
                res.push_back(i+1);
        return res;
    }
};
