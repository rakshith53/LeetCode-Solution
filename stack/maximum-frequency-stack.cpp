class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int> > m;
    int maxfreq = 0;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxfreq = max(++freq[x],maxfreq);
        m[freq[x]].push(x);
    }
    
    int pop() {
        int x = m[maxfreq].top();
        m[maxfreq].pop();
        freq[x]--;
        if(m[maxfreq].size()==0) maxfreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
