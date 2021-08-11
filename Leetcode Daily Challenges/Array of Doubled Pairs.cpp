class Solution {
public:
    bool solve(multiset<int> &s) {
        while(s.size()!=0) {
            int u = *s.rbegin();
            s.erase(s.find(u));
            if(u&1) return false;
            int v = u/2;
            if(s.find(v) == s.end()) return false;
            s.erase(s.find(v));
        } 
        return true;
    }
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> pos, neg;
        for(auto &i : arr) if(i >= 0) pos.insert(i); else neg.insert(-i);
        return solve(pos) && solve(neg);
    }
};
