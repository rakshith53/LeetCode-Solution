class Solution {
public:
    vector<string> uncommonFromSentences(string a, string b) {
        vector<string> res;
        unordered_map<string,int> m;
        stringstream s(a + " " + b);
        while(s >> a) m[a]++;
        for(auto a: m)
            if(a.second==1)
                res.push_back(a.first);
        return res;
    }
};
