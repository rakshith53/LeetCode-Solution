class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int s = a[0];
        int f = a[a[0]];
        while(s!=f){
            s = a[s];
            f = a[a[f]];
        }
        s = 0;
        while(s!=f)
        {
            s = a[s];
            f = a[f];
        }
        return f;
    }
};
