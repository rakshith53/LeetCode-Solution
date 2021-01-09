class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        stack<int> s;
        int j=0,n=a.size(),i;
        for(i=0;i<n;i++){
            s.push(a[i]);
            while(!s.empty() && s.top()==b[j] && j<n){
                s.pop();
                j++;
            }
        }
        return j==n;
    }
};
