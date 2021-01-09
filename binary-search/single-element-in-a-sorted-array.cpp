class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l=0, r=a.size()-1,mid;
        while(l<r){
            mid = (r-l)/2+l;
            if(mid%2==1) mid--;
            if(a[mid]!=a[mid+1]) r = mid;
            else  l = mid+2;
        }
        return a[l];
    }
};
