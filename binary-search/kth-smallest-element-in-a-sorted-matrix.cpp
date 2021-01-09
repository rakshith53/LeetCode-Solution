class Solution {
public:
    int kthSmallest(vector<vector<int> >& a, int k) {
        priority_queue<int> q;
        int n = a.size(),m = a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(q.size()<k)
                    q.push(a[i][j]);
                else{
                    if(q.top() > a[i][j]){
                        q.pop();
                        q.push(a[i][j]);
                    }
                }
            }
        }
        return q.top();
    }
};
