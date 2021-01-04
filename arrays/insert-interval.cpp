class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& a, vector<int>& b) {
        int n = a.size();
        bool ins = false;
        vector<vector<int> > res;
        for(int i=0;i<n;i++){
            if(ins || b[0] > a[i][1])
                res.push_back(a[i]);
            else if(b[1] < a[i][0]){
                res.push_back(b);
                res.push_back(a[i]);
                ins = true;
            }
            else{
                b[0] = min(b[0],a[i][0]);
                b[1] = max(b[1],a[i][1]);
            }
        }
        if(!ins) res.push_back(b);
        return res;
        // vector<vector<int> > ans;
        // a.push_back(b);
        // int n = a.size();
        // sort(a.begin(),a.end());
        // int pre_s = a[0][0],pre_e = a[0][1],cur_s,cur_e;
        // for(int i=1;i<n;i++)
        // {
        //     cur_s = a[i][0];
        //     cur_e = a[i][1];
        //     if(pre_e >= cur_s){
        //         pre_e = max(cur_e,pre_e);
        //     }
        //     else{
        //         ans.push_back(vector<int>{pre_s,pre_e});
        //         pre_s = cur_s;
        //         pre_e = cur_e;
        //     }
        // }
        // ans.push_back(vector<int>{pre_s,pre_e});
        // return ans;
    }
};
