class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        if(n<=1) return true;
        if(a[0]==0) return false;
        int r = n-1;
        for(int i=n-1;i>=0;i--){
            if(a[i]+i>=r)
                r = i;
        }
        return r==0;
    }
};
