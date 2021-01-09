class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool f = 0;
        if(n<0) f = 1;
        n = abs(n);
        while(n>0){
            if(n&1) res = res * x;
            x = x*x;
            n=n>>1;
        }
        if(f) return(1/res);
        return res;
    }
};
