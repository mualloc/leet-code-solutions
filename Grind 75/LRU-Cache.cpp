class LRUCache {
public:
    LRUCache(int capacity) : kCapacity(capacity) {}
    
    int get(int key) {
        auto it = map.find(key);
        if(map.end() == it) return -1;
        else{
            history.splice(history.end(), history, it->second);
            return it->second->second;
        }       
    }
    
    void put(int key, int value) {
        if(auto it = map.find(key);  it != map.end()){     // Key already exists
            history.splice(history.end(), history, it->second);
            it->second->second = value;
        }else{
            if(map.size() == kCapacity){
                map.erase(history.front().first); history.pop_front();
            }
            history.emplace_back(key, value);
            map[key] = prev(history.end());
        }
    }
    
private:
    const int kCapacity;
    std::list<pair<int, int>> history;
    unordered_map<int, std::list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */