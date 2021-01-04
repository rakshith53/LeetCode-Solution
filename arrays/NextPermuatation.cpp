class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size(),i = n-2;
        while(i>=0){
            if(a[i] < a[i+1]){
                break;
            }
            i--;
        }
        if(i>=0){
            int j = n-1;
            while(j>i && a[i] >= a[j])
                j--;
            swap(a[j],a[i]);
        }
        reverse(a.begin()+i+1,a.end());
    }
};
