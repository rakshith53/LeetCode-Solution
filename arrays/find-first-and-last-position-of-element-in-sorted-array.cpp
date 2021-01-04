class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int n = a.size();
        int l=0,r=n-1,start=-1,end=-1,mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(a[mid]==t) start = mid;
            if(a[mid]>=t) r = mid-1;
            else l = mid+1;
        }
        l = 0,r = n-1;
        while(l<=r){
            mid = l + (r-l)/2;
            if(a[mid]==t) end = mid;
            if(a[mid]<=t) l = mid+1;
            else r = mid-1;
        }
        vector<int> res(2);
        res[0] = start;
        res[1] = end;
        return res;
    }
};
