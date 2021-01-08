/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    unordered_map<int,Employee*> m;
    int sum = 0;
    void dfs(int id) {
        sum += m[id]->importance;
        for(auto i: m[id]->subordinates) dfs(i);
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto i:employees) 
            m[i->id] = i;
        dfs(id);
        return sum;
    }
};
