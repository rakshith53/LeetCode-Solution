class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& a) {
        sum.resize(a.size()+1);
        int n = a.size();
        for(int i=0;i<n;i++){
            sum[i+1] = sum[i]+a[i];
        }
    }
    
    int sumRange(int i, int j) {
        return(sum[j+1]-sum[i]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
