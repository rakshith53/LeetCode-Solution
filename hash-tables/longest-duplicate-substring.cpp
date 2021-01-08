class Solution {
public:
    #define p 10000009
    vector<int> roll;
    bool match(string s,int n,int size,string& str){
        int hash = 0;
        unordered_map<int,vector<int> > m;
        for(int i=0;i<size;i++){
            hash = (hash*26 + (s[i]-'a'))%p;
        }
        m[hash].push_back(0);
        string cur="",tmp="";
        for(int i=size;i<n;i++){
            hash = ((hash - roll[size-1]*(s[i-size]-'a'))%p+p)%p;
            hash = (hash*26 + (s[i]-'a'))%p;
            if(m.find(hash)!=m.end()){
                tmp = s.substr(i-size+1,size);
                for(int a: m[hash]){
                    cur = s.substr(a,size);
                    if(tmp.compare(cur)==0){
                        str = cur;
                        return true;
                    }
                }
            }
            m[hash].push_back(i-size+1);
        }
        return false;
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        roll.resize(n,0);
        roll[0] = 1;
        for(int i=1;i<n;i++) roll[i] = (roll[i-1]*26)%p;
        int l=1,r=n,mid;
        bool f;
        string tmp="",ans="";
        while(l<=r){
            mid = l+(r-l)/2;
            f = match(s,n,mid,tmp);
            if(f){
                if(tmp.size() > ans.size())
                    ans = tmp;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};
