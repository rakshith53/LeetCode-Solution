class Solution {
public:
    void sortColors(vector<int>& a) {
        int l = 0;
        int r = a.size()-1;
        int cur = 0;
        while(cur<=r)
        {
            if(a[cur]==0)
                swap(a[l++],a[cur++]);
            else if(a[cur]==2)
                swap(a[cur],a[r--]);
            else cur++;
        }
    }
};
