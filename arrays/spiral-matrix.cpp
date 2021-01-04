class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> res;
        if(a.size()==0) return res;
        int left = 0,top = 0,right = a[0].size()-1,bottom = a.size()-1,i;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++)
                res.push_back(a[top][i]);
            for(int i=top+1;i<=bottom;i++)
                res.push_back(a[i][right]);
            if(left<right && top<bottom){
                for(int i=right-1;i>left;i--)
                    res.push_back(a[bottom][i]);
                for(int i=bottom;i>top;i--)
                    res.push_back(a[i][left]);
            }
            left++;
            top++;
            bottom--;
            right--;
        }
        return res;
    }
};
