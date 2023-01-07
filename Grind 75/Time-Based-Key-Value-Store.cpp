class TimeMap {
public:
    void set(string key, string value, int timestamp) {
        store[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        unordered_map<string, vector<pair<int, string>>>::iterator it = store.find(key);
        if(store.end() == it) return "";
        
        const vector<pair<int, string>> & tSVPairs = it->second;
        auto upper = upper_bound(tSVPairs.begin(), tSVPairs.end(), make_pair(timestamp, ""),
                    [](const pair<int,string>  &e1, const pair<int,string>  &e2) {return e1.first < e2.first;});        
        
        return upper == tSVPairs.begin() ? "" : prev(upper)->second;
    }
       
private:
    unordered_map<string, vector<pair<int, string>>> store;  
    
    /*void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        unordered_map<string, map<int, string>>::iterator it = store.find(key);
        if(store.end() == it) return "";
        
        auto upper = it->second.upper_bound(timestamp); 
        return upper == it->second.begin() ? "" : prev(upper)->second;
    }
       
private:
    unordered_map<string, map<int, string>> store;*/
    
/*public:    
    void set(string key, string value, int timestamp) {
        store[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if(store.end() == store.find(key)) return "";
        else if(store[key].front().first > timestamp) return "";        
        else return binarySearch(store[key], timestamp);
    }
    
private:
    const string & binarySearch(const vector<pair<int, string>> & store, int value){
        int left = 0, right = store.size() - 1;
                
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            if(store[mid].first == value) return store[mid].second;
            else if(store[mid].first < value) left = mid;
            else right = mid;
            //else right = mid - 1;
        }  
        
        if(store[left].first > value) return "";
        else if(store[right].first > value) return store[left].second;
        else return abs(store[left].first - value) < abs(store[right].first - value) ? store[left].second : store[right].second;
    }    

    string binarySearch2(const vector<pair<int, string>> & store, int value){
        int left = 0, right = store.size() - 1;
        string result = "";
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(store[mid].first == value) return store[mid].second;
            else if(store[mid].first < value) result = store[mid].second, left = mid + 1;
            else right = mid - 1;
        }
        return result;
    }    
    
    const string & binarySearch3(const vector<pair<int, string>> & store, int value){
        int left = 0, right = store.size() - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(store[mid].first == value) return store[mid].second;
            else if(store[mid].first < value) left = mid + 1;
            else right = mid - 1;
        }
        
        return store[right].second;
    }
    
    unordered_map<string, vector<pair<int, string>>> store;*/
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */