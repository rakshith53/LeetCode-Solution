class Solution {
public:
    struct comp{
        bool operator() (pair<int,string>& a,pair<int,string>& b){
            if(a.first != b.first) return a.first > b.first;
            else return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(string s:words) m[s]++;
        priority_queue<pair<int,string>,vector<pair<int,string> >, comp > q;
        for(auto it=m.begin();it!=m.end();it++){
            q.push({it->second,it->first});
            if(q.size() > k) q.pop();
        }
        vector<string> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
