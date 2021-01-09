class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int> > q;
    int k;
    KthLargest(int cap, vector<int>& nums) {
        k = cap;
        for(int i:nums){
            if(q.size() < k) q.push(i);
            else{
                if(i>q.top()){
                    q.pop();
                    q.push(i);
                }
            }
        }
    }
    int add(int val) {
        if(q.size()<k) q.push(val);
        else if(val > q.top()){
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
