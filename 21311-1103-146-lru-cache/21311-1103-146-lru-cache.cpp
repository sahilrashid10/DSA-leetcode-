class LRUCache {
public:
    class node{
        public:
        int value;
        node* next, *prev;
        node(){
            value = -1;
            next = NULL;
            prev = NULL;
        }
        node(int val){
            value=val;
            next = NULL;
            prev=NULL;
        }

    };
    int capacity;
    unordered_map<int, node*>mp;
    node* head= new node();
    node* tail= new node();
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void add_node(node* &nd, int val){
        //adding node in the beninging
        nd->value = val;
        nd->next = head->next;
        nd->next->prev = nd;
        nd->prev = head;
        head->next = nd;
    }
    void remove_node(node* &nd){
        //removing node at end
        nd->next->prev = nd->prev;
        nd->prev->next = nd->next;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* nd = mp[key];
            remove_node(nd);
            add_node(nd, nd->value);
            return nd->value;
        }
        return -1;
            
    }
    
    void put(int key, int val) {
        node* nd;
        if(mp.find(key)!=mp.end()){
            nd = mp[key];
            nd->value = val;
            remove_node(nd);
            add_node(nd, val);
            mp[key] = nd;
        }
        else{
            nd = tail->prev;
            int x;
            if(mp.size() == capacity){
                for (const auto& pair : mp) {
                    if (pair.second == nd) {
                    x = pair.first;  // Found the key for the given value
                    break;
                    }
                }
                mp.erase(x);
                remove_node(nd);
                add_node(nd, val);
                mp[key] = nd;
            }
            else{
                nd = new node(val);
                mp[key] = nd;
                add_node(nd, val);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */