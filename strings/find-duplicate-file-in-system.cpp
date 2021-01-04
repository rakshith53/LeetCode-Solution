class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string> > mp;
        vector<vector<string> > res;
        string root,s,cont,name;
        for(string a:paths){
            stringstream ss(a);
            getline(ss,root,' ');
            while(getline(ss,s,' ')){
                name = root + "/" + s.substr(0,s.find('('));
                cont = s.substr(s.find('(')+1,s.find('(') - s.find(')')-1);
                mp[cont].push_back(name);
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++)
            if(it->second.size() > 1)
                res.push_back(it->second);
        return res;
    }
};
