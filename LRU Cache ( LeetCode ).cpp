// Node class to store the data in the List ( or Cache memory )
class Node {
public:
    int key;
    int value;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};


// LRU Cache Class Implementation
class LRUCache {
    int cap;
    list<Node> l;

    // Here, unordered_map<int,Node*> won't work as we are using some functions which return an iterator
    // of list type,so we are using unordered_map<int,list<Node>::iterator>
    unordered_map<int, list<Node>::iterator> m;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {

        // If key is present in the cache, then
        // a) get the value strored in 'ans'
        // b) push the copy of node to the top of the Cache memory, delete that one
        // c) update the address in map
        if (m.count(key) != 0) {

            auto it = m[key];
            int ans = it->value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return ans;
        }

        return -1;
    }

    void put(int key, int value) {

        // If key is already present in the cache, then
        // a) we just need to update the value
        // b) push the copy of node to the top of the Cache memory, delete that one
        // c) update the address in map
        if (m.count(key) != 0) {

            auto it = m[key];
            it->value = value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();

        }
        else {

            // Before inserting a new {key,value} pair, checking whether the size of Cache memory is full
            // if yes, then
            // a) deleting the last Node of the linked list (Cache Memory)
            // b) deleting the key from the map as well
            if (l.size() == cap) {
                auto it = l.back();
                m.erase(it.key);
                l.pop_back();
            }

            Node* n = new Node(key, value);
            l.push_front(*n);
            m[key] = l.begin();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
