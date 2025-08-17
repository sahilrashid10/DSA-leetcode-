class LRUCache {
public:
    class Node{
    public:
        Node* prev;
        Node* next;
        int val;
        int key;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            prev=nullptr;
            next=nullptr;
        }
    };
    Node* head;
    Node* tail;

    // map -> key, Node(key, value)
    unordered_map<int, Node*> mp;
    int capacity;
    int size = 1;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        Node *curNode = mp[key];

        removeNode(curNode);
        insertNode(curNode);

        return curNode->val;
    }
    
    void put(int key, int value) {
        Node *curNode;
    
        if(mp.find(key) != mp.end()){
            curNode = mp[key];
            curNode->val = value;
            removeNode(curNode);
            insertNode(curNode);
        }else{
        // 2- The key isn't in the map
            if(size <= capacity){
                size++;
                curNode = new Node(key, value);
                mp[key] = curNode;
                insertNode(curNode);
            }else{
                curNode = tail->prev;
                int toDelete = curNode->key;
                curNode->val = value;
                curNode->key = key;
                mp[key] = curNode;
                mp.erase(toDelete);

                removeNode(curNode);
                insertNode(curNode);
            }
        }

    }
private:
    void removeNode(Node* node){

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertNode(Node* node){
        if(head->next == tail){
            head->next = node;
            node->prev = head;

            node->next = tail;
            tail->prev = node;

        }else{
            node->next = head->next;
            head->next = node;
            node->next->prev = node;
            node->prev = head;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */