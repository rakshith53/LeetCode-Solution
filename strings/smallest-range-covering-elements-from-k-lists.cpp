class Solution {
public:
    typedef vector<int>::iterator it;
    vector<int> smallestRange(vector<vector<int> >& a) {
        vector<int> ans(2);
        struct comp{
            bool operator()(pair<it,it> a,pair<it,it> b){
                return *a.first > *b.first;
            }
        };
        priority_queue<pair<it,it>,vector<pair<it,it> >,comp > q;
        int n = a.size(),l = INT_MAX,r = INT_MIN;
        for(int i=0;i<n;i++){
            l = min(l,a[i][0]);
            r = max(r,a[i][0]);
            q.push({a[i].begin(),a[i].end()});
        }
        pair<it,it> p;
        ans[0] = l;
        ans[1] = r;
        int len = r-l;
        while(!q.empty()){
            p = q.top();
            q.pop();
            p.first++;
            if(p.first == p.second) break;
            q.push(p);
            l = *q.top().first;
            r = max(r,*p.first);
            if(len > (r-l)){
                len = r-l;
                ans[0] = l;
                ans[1] = r;
            }
        }
        return ans;
    }
};
