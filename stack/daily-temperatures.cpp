class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<int> s;
        int n = a.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            while(!s.empty() && a[s.top()] < a[i]){
                res[s.top()] =  i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
