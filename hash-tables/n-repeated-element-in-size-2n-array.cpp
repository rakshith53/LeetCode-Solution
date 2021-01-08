class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        int n = a.size();
        for(int k=1;k<=3;k++)
            for(int i=0;i<n-k;i++)
                if(a[i] == a[i+k])
                    return a[i];
        return -1;
    }
};
