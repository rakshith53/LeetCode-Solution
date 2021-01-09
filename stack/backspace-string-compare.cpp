class Solution {
public:
    string help(string str)
    {
        stack<char> s;
        int n = str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]!='#')
                s.push(str[i]);
            else if(!s.empty())
                s.pop();
                
        }
        string ans = "";
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return !(help(s).compare(help(t)));
    }
};
