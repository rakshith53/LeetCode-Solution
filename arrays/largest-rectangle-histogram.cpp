class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> s;
        int ans = 0,n = a.size(),t,i=0;
        while(i<n){
            if(s.empty())
                s.push(i++);
            else if(a[i]>a[s.top()]){
                s.push(i++);
            }
            else{
                t = s.top();
                s.pop();
                if(s.empty()) ans = max(ans,a[t]*i);
                else ans = max(ans,a[t]*(i-1-s.top()));
            }
        }
        while(!s.empty()){
            t = s.top();
            s.pop();
            if(s.empty()) ans = max(ans,a[t]*i);
            else ans = max(ans,a[t]*(i-1-s.top()));
        }
        return ans;
    }
};
