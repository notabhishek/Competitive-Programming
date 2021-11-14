class CombinationIterator {
public:
    string s;
    int n;
    int k;
    string cur;
    bool hasPrevPerm;
    CombinationIterator(string characters, int combinationLength) {
        k = combinationLength;
        s = characters;
        n = s.length();
        sort(s.begin(), s.end());
        cur = string(k, '1') + string(n-k, '0');
        hasPrevPerm = true;
    }
    
    string next() {
        string res = "";
        for(int i = 0; i < n; ++i) 
            if(cur[i]=='1') res += s[i];
        
        hasPrevPerm = prev_permutation(cur.begin(), cur.end());
        return res;  
    }
    
    bool hasNext() {
        return hasPrevPerm;
    }
    
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
