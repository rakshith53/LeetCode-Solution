class Solution {
public:
    bool issame(vector<int>& a,vector<int>& b){
        return a[0]==b[0] && a[1]==b[1];
    }
    
    long double getslope(vector<int>& a,vector<int>& b){
        if(a[0] == b[0]) return (long double)INT_MAX;
        if(a[1] == b[1]) return 0;
        return (long double)(a[1]-b[1])/(long double)(a[0]-b[0]);
    }
    int maxPoints(vector<vector<int>>& p) {
        int ans = 0,n = p.size(),same,local_max,i=0;
        long double slope;
        while(i<n){
            unordered_map<long double,int> m;
            same = 1;
            local_max = 0;
            for(int j=i+1;j<n;j++){
                if(issame(p[i],p[j])){
                    same++;
                    continue;
                }
                slope = getslope(p[i],p[j]);
                m[slope]++;
                local_max = max(local_max,m[slope]);
            }
            ans = max(ans,local_max+same);
            i++;
        }
        return ans;
    }
};
