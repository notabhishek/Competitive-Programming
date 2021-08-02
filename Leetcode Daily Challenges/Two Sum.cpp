class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        set< pair<int, int>> s;
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            s.insert({a[i], i});
        }
        for(int i = 0; i < n; ++i) {
            s.erase({a[i], i});
            auto it = s.lower_bound({k - a[i] , -1});
            if(it != s.end() && (*it).first == k-a[i]) {
                return {i, (*it).second};
            }
            s.insert({a[i], i});
        }
        return {-1,-1};
    }
};
