class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (auto i : arr1) m[i]++;
        int pos = 0,k;
        for (auto j : arr2) {
            while(m[j]--) arr1[pos++] = j;
        }
        for (auto& it : m) {
            k = it.second;
            while(k-->0) arr1[pos++] = it.first;
        }
        return arr1;
    }
};
