class Solution {
public:
    bool isPalindrome(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]) {
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> m;
        string key,left,right;
        int n = words.size(),k;
        for(int i=0;i<n;i++){
            key = words[i];
            reverse(key.begin(),key.end());
            m[key] = i;
        }
        vector<vector<int> > res;
        for(int i=0;i<n;i++){
            k = words[i].size();
            for(int j=0;j<k;j++){
                left = words[i].substr(0,j);
                right = words[i].substr(j);
                if(m.find(left)!=m.end() && m[left]!=i && isPalindrome(right)){
                    res.push_back({i,m[left]});
                    if(left.empty()){
                        res.push_back({m[left],i});
                    }
                }
                if(m.find(right)!=m.end() && m[right]!=i && isPalindrome(left)){
                    res.push_back({m[right],i});
                }
            }
        }
        return res;
    }
};
