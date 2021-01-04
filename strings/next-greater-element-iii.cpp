class Solution {
public:
    int nextGreaterElement(int n) {
        stack<int> s;
        vector<int> num;
        
        while(n) {
            s.push(n % 10);
            n = n/10;
        }
        while(!s.empty()) {
            num.push_back(s.top());
            s.pop();
        }
        if (num.size() < 2) return -1;
        return nextGreater(num);
    }
    
    int nextGreater(vector<int> &num) {
        bool flag = false;
        int index = -1;
        int number = 0;
        
        for (int i=1;i<num.size();++i) {
            if (num[i-1] < num[i]) {
                flag = true;
                break;
            }
        }
        if (!flag) return -1;
        for (int i=num.size()-1;i>=1;--i) {
            if (num[i] > num[i-1]) {
                index = i-1;
                break;
            }
        }
        //int next = num[index+1];
        int nextIndex = index + 1;
        for (int i=nextIndex;i<num.size();++i) {
            if (num[index] < num[i] && num[i] < num[nextIndex]) {
                nextIndex = i;
            }
        }
        std::swap(num[index], num[nextIndex]);
        std::sort(num.begin()+index+1, num.end());
        for (int i=0;i<num.size();++i) {
            if (number > (INT_MAX/10)) return -1;
            number = number * 10 + num[i];
        }
        //std::cout << index << " " << nextIndex << endl;
        
        return number;
    }
};
/*
4 6 6 3 2 1
    
6 1 2 3 4 6
6 6 1 2 3 4*/
