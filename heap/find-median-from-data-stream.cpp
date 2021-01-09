class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int> > min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max.empty() || max.top() > num)
            max.push(num);
        else min.push(num);
        
        if(min.size() > max.size()+1){
            max.push(min.top());
            min.pop();
        }
        
        if(max.size() > min.size()+1){
            min.push(max.top());
            max.pop();
        }
    }
    
    double findMedian() {
        if(min.size() == max.size())
            return (double)(min.top()+max.top())/2;
        else if(min.size() > max.size())
            return min.top();
        else 
            return max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
