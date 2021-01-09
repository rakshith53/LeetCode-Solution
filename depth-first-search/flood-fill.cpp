class Solution {
public:
    int n,m;
    bool isValid(int x,int y){
        if(x<0 || x==n || y<0 || y==m) return false;
        return true;
    }
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        n = image.size();
        if(n==0) return image;
        m = image[0].size();
        if(image[sr][sc] == newColor) return image;
        queue<pair<int,int> > qu;
        qu.push({sr,sc});
        pair<int,int> cur;
        int r[4] = {0,0,1,-1};
        int c[4] = {1,-1,0,0};
        int x,y,p,q;
        int val = image[sr][sc];
        image[sr][sc] = newColor;
        while(!qu.empty()){
            cur = qu.front();
            qu.pop();
            x = cur.first;
            y = cur.second;
            // image[x][y] = newColor;
            for(int i=0;i<4;i++){
                p = x+r[i];
                q = y+c[i];
                if(isValid(p,q) && image[p][q]==val){
                    qu.push({p,q});
                    image[p][q] = newColor;
                }
            }
        }
        return image;
    }
};
