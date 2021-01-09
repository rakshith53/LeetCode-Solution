class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0,r = n,sum,ans,mid;
        while(l<=r){
            mid = (r-l)/2 +l;
            sum = mid*(mid+1)/2;
            if(n == mid*(mid+1)/2) return mid;
            else if(sum > n) r = mid-1;
            else l = mid+1;
        }
        return r;
    }
};
