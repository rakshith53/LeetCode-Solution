class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> s;
        s.push_back(INT_MAX);
        int res = 0,mid;
        for(int a:arr){
            while(s.back() <= a){
                mid = s.back();
                s.pop_back();
                res += mid*min(s.back(),a);
            }
            s.push_back(a);
        }
        for(int i=2;i<s.size();i++){
            res += s[i]*s[i-1];
        }
        return res;
    }
};
