class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string> res;
        int j=0,i=1,m = t.size();
        while(j<m){
            if(t[j]==i){
                i++;
                j++;
                res.push_back("Push");
            }
            else{
                res.push_back("Push");
                res.push_back("Pop");
                i++;
            }
        }
        return res;
    }
};
