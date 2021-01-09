class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        unordered_map<int,int> m;
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<a.size();i++)
        {
            if(pq.size()<k) pq.push(a[i]);
            else{
                if(a[i] > pq.top()){
                    pq.pop();
                    pq.push(a[i]);
                }
            }
        }
        return pq.top();
    }
};
