/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int elem = obj -> get(key);
 * obj -> put(key,value);
 */
// linked list implementation : https://ideone.com/UptQ87 (wa on 2 cases)
class LRUCache {
public:
    deque<pair<int,int>> dq;
    unordered_map<int, deque<pair<int,int>>::iterator> hash;
    int Capacity;
    LRUCache(int capacity) {
		Capacity = capacity;
        dq.clear();
        hash.clear();
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;
        deque<pair<int,int>>::iterator element = hash[key];
        int value = element->second;
        dq.erase(element);
        dq.push_front({key,value});
        hash[key] = dq.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(hash.find(key) == hash.end()){
        	// new key is inserted
            if(dq.size() == Capacity) {
            	hash.erase(dq.back().first);
                dq.pop_back();
            }
            dq.push_front({key,value});
            hash[key] = dq.begin();
        } else {
            // already exists 
            deque<pair<int,int>>::iterator it = hash[key];
            hash.erase(key);
            dq.erase(it);
            
            dq.push_front({key,value});
            hash[key] = dq.begin();
        }
    }
};
