class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> res;
        int i=0,cnt=0,n=s.size();
        string ans="",tmp="",tmp2;
        while(i<n)
        {
            if(isdigit(s[i])){
                cnt=0;
                while(isdigit(s[i]))
                {
                    cnt = cnt*10+(s[i]-'0');
                    i++;
                }
              num.push(cnt);
            }
            else if(s[i]=='['){
                res.push(ans);
                ans="";
                i++;
            }
            else if(s[i]==']'){
                tmp = res.top(); res.pop();
                cnt = num.top(); num.pop();
                for(int i=0;i<cnt;i++)
                {
                    tmp+=ans;
                }
                ans = tmp;
                i++;
            }
            else{
                ans+=s[i++];
            }
        }
        return ans;
    }
};
