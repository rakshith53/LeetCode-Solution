class Solution {
public:
    int n;
    bool dfs(vector<int>& a,vector<bool>& v,int ind,int csum,int k,int sum){
        if(k==0) return true;
        if(csum==sum) return dfs(a,v,0,0,k-1,sum);
        for(int i=ind;i<n;i++){
            if(!v[i]){
                if(csum+a[i]<=sum){
                    v[i] = true;
                    if(dfs(a,v,i+1,csum+a[i],k,sum)) 
                        return true;
                    v[i] = false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int sum = 0,mx=0;
        for(int i:nums){
            sum += i;
            mx = max(mx,i);
        }
        if(sum%k || mx>sum) return false;
        sort(nums.rbegin(),nums.rend());
        vector<bool> vis(n,false);
        return dfs(nums,vis,0,0,k,sum/k);
    }
};
