class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int l = 0,r = a.size()-1,mid;
        while(l<r)
        {
            mid = l+(r-l)/2;
            if(a[mid] > a[mid+1])
                r = mid;
            else l =mid+1;
        }
        return l;
    }
};
