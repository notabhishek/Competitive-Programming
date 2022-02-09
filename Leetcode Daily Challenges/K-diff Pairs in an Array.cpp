class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> s;
        set<pair<int, int>> res;
        int ans = 0;
        for(int i : nums) {
            if(s.count(i-k))
                res.insert({i-k, i});
            if(s.count(i+k))
                res.insert({i, i+k});
            s.insert(i);
        }
        // for(auto p : res) cout << p.first << " " << p.second << endl;
        return res.size();
    }
};
