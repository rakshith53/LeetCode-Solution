class Solution {
public:
    struct comp{
       bool operator()(pair<int,int> &p1,pair<int,int> &p2){
           return (p1.first*p1.first+p1.second*p1.second)>(p2.first*p2.first+p2.second*p2.second);
       }  
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
          
        vector<vector<int>> ans(K);
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        for(auto it : points){
            pq.push({it[0],it[1]});
        }
        int i  =0 ;
        while(K--){
            ans[i]={pq.top().first,pq.top().second}; pq.pop();
            i++;
        }
        return ans;
    }
};
