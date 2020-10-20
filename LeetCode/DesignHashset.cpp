class MyHashSet {
int tot = 1000000;
int sz = 1000;    
vector<set<int>> myhash;
    int comp_slot(int key){
        int num_slot = tot/sz;
        int slot = floor(key/num_slot);
        return slot;
    }    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        for(int i=0;i<sz;++i){
            set<int> set1;
            myhash.push_back(set1);
        }                    
    }
    
    void add(int key) {
        // Compute the index
        int slot = comp_slot(key);
        // Insert in the set
        myhash[slot].insert(key);
    }
    
    void remove(int key) {
        int slot = comp_slot(key);
        myhash[slot].erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int slot = comp_slot(key);
        return (bool)myhash[slot].count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
