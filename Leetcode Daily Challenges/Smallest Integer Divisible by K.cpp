class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int len = 1, r = 1%k;
        unordered_set<int> rem;
        rem.insert(r);
        while(r != 0) {
            r = (r*10 + 1)%k;
            if(rem.find(r) != rem.end()) return -1;
            rem.insert(r);
            ++len;
        }
        return len;
    }
};
