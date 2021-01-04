class Solution {
public:
    int majorityElement(vector<int>& a) {
        int cnt=0,ele;
        for(int i: a)
        {
            if(cnt==0){
              ele = i;  
            }
            cnt += (i==ele ? 1: -1);
        }
        return ele;
    }
};
