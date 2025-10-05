class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) 
            return false;
        
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int idx = m[val];
            v[idx] = v.back();
            m[v[idx]] = idx;
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int t = rand() % m.size();
        return v[t];  
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */