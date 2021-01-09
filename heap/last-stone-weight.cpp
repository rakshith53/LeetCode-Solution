class Solution {
public:
    int lastStoneWeight(vector<int>& ar) {
        priority_queue <int> q;
        int n = ar.size();
        for(int i=0;i<n;i++)
        {
            q.push(ar[i]);
        }
        int a,b;
        while(q.size()>2)
        {
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            if(a!=b) q.push(abs(a-b));
        }
        if(q.size()==2)
        {
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            if(a==b) return 0;
            if(a!=b) q.push(abs(a-b));
        }
        return q.top();
    }
};
