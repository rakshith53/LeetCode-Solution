class Solution {
public:
    int find(vector<int> &manager, vector<int> &informTime, int s, vector<int> &total){
        if(total[s] != -1) {
            return total[s];
        }
        return total[s] = informTime[manager[s]] + find(manager, informTime, manager[s], total);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> total(n, -1);
        int i, ans=0;
        total[headID] = 0;
        for(i = 0; i < n; i++) {
            ans = max(ans, find(manager, informTime, i, total));
        }
        return ans;
    }
};
