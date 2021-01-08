class Solution {
public:
    string fractionToDecimal(int a, int b) {
        if(!a) return "0";
        string ans = "";
        if (a > 0 ^ b > 0) {
            ans += '-';
        }
        long n = labs(a);
        long d = labs(b);
        ans+=to_string(n/d);
        long r = n%d;
        if(!r) return ans;
        ans+='.';
        unordered_map<long,int> m;
        while(r)
        {
            if(m.find(r)!=m.end())
            {
                ans.insert(m[r],"(");
                ans+=')';
                return ans;
            }
            m[r] = ans.size();
            r *= 10;
            ans += to_string(r/d);
            r = r%d;
        }
        return ans;
    }
};
