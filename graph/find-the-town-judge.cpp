class Solution {
public:
    int findJudge(int N, vector<vector<int> >& trust) {
        if(N<=0) return -1;
        vector< int > v(N,0); 
        for(auto x:trust){
            v[x[0]-1]--;
            v[x[1]-1]++;
        }
        for(int i = 1 ; i<=v.size(); i++){
            if(v[i-1] == N-1) return i;
        }
        return -1;
    }
};

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
