class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1,r=num;
        int mid,res,rem;
        while(l<=r){
            mid = (r-l)/2 + l;
            if(num/mid==mid && num%mid==0) return true;
            else if(mid < num/mid) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};
