class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int res = 10;
        int cnt = 9,digits = 9;
        n--;
        while(n-- && digits){
            cnt *= digits;
            res += cnt;
            digits--;
        }
        return res;
    }
};
