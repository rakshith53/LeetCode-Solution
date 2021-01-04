class Solution {
public:
    int romanToInt(string a) {
        unordered_map<char,int> m;
        m.insert({'I',1});
        m.insert({'V',5});
        m.insert({'X',10});
        m.insert({'L',50});
        m.insert({'C',100});
        m.insert({'D',500});
        m.insert({'M',1000});
        int n = a.size()-1,tmp = INT_MIN,ans=0;
        for(int i=n;i>=0;i--)
        {
            if(tmp > m[a[i]]) ans-=m[a[i]];
            else ans+=m[a[i]];
            tmp = m[a[i]];
        }
        return ans;
    }
};
