class Solution {
public:
    int findMin(vector<int>& a) {
        if(a.size()==1) return a[0];
        int r = a.size()-1,l=0,mid;
        if(a[r]>a[0]) return a[0];
        while(l<=r)
        {
            mid = (r-l)/2+l;
            if(a[mid]>a[mid+1]) return a[mid+1];
            if(a[mid-1]>a[mid]) return a[mid];
            if(a[mid]>a[r]) l = mid+1;
            else r=mid-1;
        }
        return a[l];
    }
};
