class Solution {
public:
    vector<int> res;
    int get(bitset<32>& c,int n){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum<<1;
            sum+=c[i];
        }
        return sum;
    }
    void dfs(bitset<32>& c,int k,int n){
        if(k==n){
            res.push_back(get(c,n));
            return;
        }
        dfs(c,k+1,n);
        c.flip(k);
        dfs(c,k+1,n);
    }
    vector<int> grayCode(int n) {
        bitset<32> c;
        dfs(c,0,n);
        return res;
    }
};
