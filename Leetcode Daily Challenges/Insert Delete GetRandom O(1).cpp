class RandomizedSet {
private:
    unordered_map<int, int> hashSet;
    vector<int> arr;
    int size;
public:
    RandomizedSet() {
        arr.clear();
        hashSet.clear();
        size = 0;
    }
    
    bool insert(int val) {
        if(hashSet.find(val) != hashSet.end())
            return false;
        hashSet[val] = size++;
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(hashSet.find(val) == hashSet.end())
            return false;
        int index = hashSet[val];
        arr[index] = arr[size-1];
        hashSet[arr[index]] = index;
        
        hashSet.erase(val);
        arr.pop_back();
        --size;
        return true;
    }
    
    int getRandom() {
        return arr[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
