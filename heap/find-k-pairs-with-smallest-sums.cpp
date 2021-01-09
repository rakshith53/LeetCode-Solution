class Solution {
public:
    typedef pair<int,int> pii;
    struct comp{
        bool operator()(pii& a,pii& b){
            return a.first+a.second < b.first+b.second;
        }
    };
    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        praiority_queue<pii,vector<pii>,comp> q;
        int sum;
        for(int i:nums1){
            for(int j:nums2){
                if(q.size()<k)
                    q.push({i,j});
                else{
                    sum = q.top().first + q.top().second;
                    if(sum > i+j){
                        q.pop();
                        q.push({i,j});
                    }
                }
            }
        }
        vector<vector<int> > res;
        while(!q.empty()){
            res.push_back({q.top().first,q.top().second});
            q.pop();
        }
        return res;
    }
};
