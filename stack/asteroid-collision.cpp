class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> res;
        for(int a:asteroids){
            if(s.empty() || a>0) s.push(a);
            else{
                while(!s.empty() && s.top() > 0 && s.top() < abs(a)){
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(a)) s.pop();
                else if(s.empty() || (!s.empty() && s.top() < 0)) s.push(a);
            }
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
