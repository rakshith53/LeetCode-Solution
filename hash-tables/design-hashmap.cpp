class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> map;
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if(key >= map.size()) map.resize(key+1,-1);
        map[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return key < map.size() && map[key] >= 0 ? map[key] : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(key < map.size()) map[key] = -1;
    }
};
