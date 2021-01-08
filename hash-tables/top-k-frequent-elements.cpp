class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        map<int,int> m;
        int n = a.size(),temp = k;
        vector<int> res;
        for(int i=0;i<n;i++)
            m[a[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
        auto it = m.begin();
        for(;it!=m.end() && k--;it++){
            q.push({it->second,it->first});
        }
        for(;it!=m.end();it++){
            if(it->second > q.top().first){
                q.pop();
                q.push({it->second,it->first});
            }
        }
        pair<int,int> c;
        while(!q.empty())
        {
            c = q.top();
            q.pop();
            res.push_back(c.second);
        }
        return res;
    }
};
