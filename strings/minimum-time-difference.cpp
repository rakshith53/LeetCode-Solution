class Solution {
public:
    int findMinDifference(vector<string>& a) {
        vector<int> v(a.size(),0);
        int time,i=0;
        for(auto s:a){
            time = (s[0]-'0')*10+(s[1]-'0');
            time = (time*60) + (s[3]-'0')*10+(s[4]-'0');
            v[i++] = time;
        }
        sort(v.begin(),v.end());
        int dif = INT_MAX,n = a.size(),ans=INT_MAX;
        for(int i=0;i<n;i++){
            dif = abs(v[(i+1)%n]-v[i]);
            dif = min(dif,1440-dif);
            ans = min(ans,dif);
        }
        return ans;
    }
};
