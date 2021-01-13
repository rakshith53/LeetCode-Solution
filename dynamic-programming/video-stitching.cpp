class Solution {
public:
    int videoStitching(vector<vector<int> >& a, int T) {
        sort(a.begin(),a.end());
        int start = 0,end = 0;
        int n = a.size(),res=0;
        for(int i=0;start<T;start=end,res++){
            for(;i<n && a[i][0]<=start;i++) end = max(end,a[i][1]);
            cout<<end;
            if(start==end) return -1;
        }
        return res;
    }
};
