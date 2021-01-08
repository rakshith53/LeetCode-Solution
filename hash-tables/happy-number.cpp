class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;
        while(n!=1)
        {
            int cur = n;
            int sum = 0;
            while(cur!=0)
            {
                sum += (cur%10)*(cur%10);
                cur/=10;
            }
            if(m.find(sum)!=m.end()) return false;
            m[sum]++;
            n = sum;
        }
        return true;
    }
};
