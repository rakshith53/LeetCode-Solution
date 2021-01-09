class Solution {
public:
    int n;
    void dfs(vector<vector<int> >& rooms,vector<bool>& vis,int node){
        vis[node] = true;
        for(int i:rooms[node])
            if(!vis[i])
                dfs(rooms,vis,i);
    }
    bool canVisitAllRooms(vector<vector<int> >& rooms) {
        n = rooms.size();
        vector<bool> vis(n,false);
        dfs(rooms,vis,0);
        for(bool a:vis)
            if(!a) 
                return false;
        return true;
    }
};
