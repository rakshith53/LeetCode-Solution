class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int l=0,r=a.size()-1,mid;
        while(l<=r){
            mid = (r-l)/2+l;
            if(a[mid] == t) return mid;
            else if (a[mid] > t) r = mid - 1;
            else if (a[mid] < t) l = mid + 1;
        }
        return l;
    }
};
