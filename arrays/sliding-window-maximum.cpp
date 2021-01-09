class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> q;
        int i,n = a.size();
        vector<int> res;
        for(i=0;i<k;i++){
            while(!q.empty() && a[i]>=a[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        for(i=k;i<n;i++){
            res.push_back(a[q.front()]);
            while(!q.empty() && a[i]>=a[q.back()])
                q.pop_back();
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            q.push_back(i);
        }
        res.push_back(a[q.front()]);
        return res;
    }
};
