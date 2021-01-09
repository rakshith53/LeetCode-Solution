class Solution {
public:
    int n,begin;
    bool dfs(vector<int>& a,int i){
        if(i<0 || i>=n || a[i]<0) return false;
        if(a[i]==0) return true;
        a[i] = -a[i];
        return  dfs(a,i+a[i]) || dfs(a,i-a[i]);
    }
    bool canReach(vector<int>& a, int start) {
        n = a.size();
        begin = start;
        return (dfs(a,start));
    }
};
