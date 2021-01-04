class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k%n;
        k = n-k;
        int d = __gcd(n,k),j,l,tmp;
        for(int i=0;i<d;i++){
            tmp = a[i];
            j = i;
            while(true){
                l = j+k;
                if(l>=n) l -= n;
                if(l==i) break;
                a[j] = a[l];
                j = l;
            }
            a[j] = tmp;
        }
    }
};

