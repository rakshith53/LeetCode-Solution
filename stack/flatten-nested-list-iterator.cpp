/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    #define it vector<NestedInteger>::iterator
    stack<it> start,end;
    NestedIterator(vector<NestedInteger> &nestedList) {
        start.push(nestedList.begin());
        end.push(nestedList.end());
    }
    
    int next() {
        return start.top()++->getInteger();
    }
    
    bool hasNext() {
        while(!start.empty()){
            it t = start.top();
            if(t==end.top()){
                start.pop();
                end.pop();
                if(!start.empty()) start.top()++;
            }
            else if(t->isInteger()) return true;
            else{
                vector<NestedInteger> &list = t->getList();
                start.push(list.begin());
                end.push(list.end());
            }
        }
        return false;
    }
    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
