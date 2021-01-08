class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool> set;
    int size = 0;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(key >= set.size()) set.resize(key+1,false);
        set[key] = true;
        //size = key+1;
    }
    
    void remove(int key) {
        if(key < set.size()) set[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return key < set.size() ? set[key] : false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
