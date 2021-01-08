class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> a;
        int sum = INT_MAX;
        int n = list1.size(),m = list2.size();
        vector<string> res;
        for(int i=0;i<m;i++) a[list2[i]] = i;
        for(int i=0;i<n;i++){
            if(a.find(list1[i])!=a.end()){
                if(sum > i+a[list1[i]]){
                    res.clear();
                    sum = i + a[list1[i]];
                    res.push_back(list1[i]);
                }
                else if(sum == i+a[list1[i]]){
                    res.push_back(list1[i]);
                }
            }
        }
        return res;
    }
};
